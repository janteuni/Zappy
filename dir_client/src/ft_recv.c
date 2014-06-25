/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:22:18 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/25 21:32:06 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include "client.h"

static int			ft_get_max_len(t_env *env, char *str)
{
	t_list			*ptr;
	int				len;

	len = ft_strlen(str);
	ptr = env->buffer;
	while (ptr)
	{
		len += ft_strlen((char *)ptr->content);
		ptr = ptr->next;
	}
	return (len);
}

char				*ft_join_str(t_env *env, char *str)
{
	t_list			*ptr;
	int				len;
	char			*line;
	int				i;

	if (!env->buffer)
		return (ft_strdup(str));
	line = ft_strnew(ft_get_max_len(env, str));
	ptr = env->buffer;
	i = 0;
	while (ptr)
	{
		len = ft_strlen((char *)ptr->content);
		ft_memcpy(&line[i], (char *)ptr->content, len);
		i += (len);
		ptr = ptr->next;
	}
	ft_memcpy(&line[i], str, ft_strlen(str) + 1);
	ft_lstdel(&env->buffer, ft_lstdel_elem);
	env->buffer = NULL;
	return (line);
}

static void			ft_stock_line(et_env *env, char *buf, int l, int start)
{
	if (start < l)
	{
		str = ft_strsub(buf, start, l - start);
		ft_lstpush(&env->buffer, ft_lstnew(str, ft_strlen(str) + 1));
		free(str);
	}
	ft_recv(env);
}

void				ft_read_buffer(t_env *env, char *buf, int l, int start)
{
	char			*ptr;
	char			*str;
	char			*line;

	if ((ptr = ft_memchr(buf + start, '\n', RECV_BUF - start)))
	{
		if ((str = ft_strsub(buf, start, ptr - (buf + start))))
		{
			line = ft_join_str(env, str);
			ft_read_line(env, line);
			free(str);
			free(line);
		}
		if (ptr < &buf[l - 1])
			ft_read_buffer(env, buf, l, (&ptr[1] - buf));
	}
	else
		ft_stock_line(env, buf, l, start);
}

int					ft_recv(t_env *env)
{
	char			buf[RECV_BUF];
	int				l;

	l = recv(env->socket, buf, RECV_BUF, 0);
	if (l > 0)
		ft_read_buffer(env, buf, l, 0);
	return (OK);
}
