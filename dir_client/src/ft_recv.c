/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:22:18 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/22 20:34:43 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include "client.h"

int					ft_connect_nb(t_env *env, char *buf)
{
	int				new;

	new = ft_atoi(buf);
	if (!env->laying)
		env->connect_nb = new;
	else if (new > env->connect_nb)
	{
		dprintf(env->aff, "connect nb is higher!! time to fork\n");
		env->connect_nb = new;
		ft_fork(env);
		/*env->laying = 0;
		env->forked = 1; - for when i took out fork*/
	}
	env->resp[RESP_VAL]--;
	return (OK);
}

int					ft_read_list(t_env *env, char *buf)
{
	char			*list;
	char			**split;
	char			*sp;

	(void)env;
	list = ft_strsub(buf, 1, ft_strlen(buf) - 2);
	split = ft_strsplit(list, ',');
	sp = ft_strchr(split[0], ' ');
	if (sp && sp[0] && sp[1] && ft_isdigit(sp[1]))
	{
		ft_read_inventory(env, split, 0);
		/*ft_print_inv(env);*/
		env->resp[RESP_INV]--;
	}
	else
	{
		ft_read_view(env, split);
		env->resp[RESP_VIEW]--;
	}
	free(list);
	ft_free_tab((void ***)&split);
	return (OK);
}

int					ft_read_line(t_env *env, char *line)
{
	dprintf(env->aff, "[%d]\tRECEIVED [%s]\n",env->pid,line );
	if ((line[0] == 'o') || (line[0] == 'k')) // OK / KO
	{
		if (line[0] == 'k' && env->resp[RESP_OK] == 0 && env->elevating == 1)
			ft_elev_failed(env);
		else
			env->resp[RESP_OK]--;
		return (OK);
	}
	if (line[0] == '{') // {...}
		return (ft_read_list(env, line));
	if (line[0] == 'e') // elevation en cours
		return (ft_begin_elev(env, line));
	if (line[0] == 'n') // niveau actuel
		return (ft_end_elev(env, line));
	if (line[0] == 'd') // deplacement <K>
		return (ft_move(env, line));
	if (line[0] == 'm' && !ft_strncmp(DEAD, line, ft_strlen(DEAD))) // mort
		return (ft_dead(env, line));
	if (line[0] == 'm' && !ft_strncmp(MSG, line, ft_strlen(MSG))) // message <msg>
		return (ft_message(env, line));
	if (ft_isdigit(line[0])) // CONNECT_NB
		return (ft_connect_nb(env, line));
	else
		dprintf(env->aff, "[%d]\tI do not understand '%s'\n", env->pid,line);
	return (OK);
}
/*
int					ft_recv(t_env *env)
{
	char			buf[BIG_BUF + 1];
	char			**lines;
	int				i;

	ft_bzero(buf, BIG_BUF + 1);
	recv(env->socket, buf, BIG_BUF, 0);
	lines = ft_strsplit(buf, '\n');
	i = -1;
	while (lines[++i])
		ft_read_line(env, lines[i]);
	return (OK);
}*/

char			*ft_join_str(t_env *env, char *str)
{
	t_list		*ptr;
	int			len;
	char		*line;
	int			i;

	if (!env->buffer)
		return (ft_strdup(str));
	ptr = env->buffer;
	len = ft_strlen(str);
	while (ptr)
	{
		len += ft_strlen((char *)ptr->content);
		ptr = ptr->next;
	}
	line = ft_strnew(len);
	ptr = env->buffer;
	i = 0;
	while (ptr)
	{
		/*printf("STRING IN LIST IS [%s]\n", (char *)ptr->content );*/
		len = ft_strlen((char *)ptr->content);
		ft_memcpy(&line[i], (char *)ptr->content, len);
		i += (len);
		/*printf("i = %d, line so far ... [%s]\n",i, line );*/
		ptr = ptr->next;
	}
	ft_memcpy(&line[i], str, ft_strlen(str) + 1);
	ft_lstdel(&env->buffer, ft_lstdel_elem);
	env->buffer = NULL;
	return (line);
}

int					ft_read_buffer(t_env *env, char *buf, int l, int start)
{
	char			*ptr;
	char			*str;
	char			*line;

	if ((ptr = ft_memchr(buf + start, '\n', RECV_BUF - start)))
	{
		if ((str = ft_strsub(buf, start, ptr - (buf + start))))
		{
			line = ft_join_str(env, str);
			/*printf("CONCATENATED STR THAT IM SENDING TO READ LINE [%s]\n",line );*/
			ft_read_line(env, line);
			free(str);
			free(line);
		}
		if (ptr < &buf[l - 1])
			ft_read_buffer(env, buf, l, (&ptr[1] - buf));
	}
	else
	{
		if (start < (l - 1))
		{
			str = ft_strsub(buf, start, l - start);
			ft_lstpush(&env->buffer, ft_lstnew(str, ft_strlen(str) + 1));
		}
		ft_recv(env);
	}
	return (OK);

}

int					ft_recv(t_env *env)
{
	char			buf[RECV_BUF];
	/*char			**lines;
	int				i;*/
	int				l;

	ft_bzero(buf, RECV_BUF);
	/*env->buf_offset += recv(env->socket, buf + env->buf_offset,
			RECV_BUF - env->buf_offset, 0);*/
	l = recv(env->socket, buf, RECV_BUF, 0);
	if (l)
		ft_read_buffer(env, buf, l, 0);
/*	lines = ft_strsplit(buf, '\n');
	i = -1;
	while (lines[++i])
		ft_read_line(env, lines[i]);*/
	return (OK);
}
