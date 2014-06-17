/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:22:18 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/17 21:32:32 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include "client.h"

int					ft_connect_nb(t_env *env, char *buf)
{
	int				new;

	new = ft_atoi(buf);
	printf("RECIEVED CONNECT_NB [%s]\n",buf );
	if (!env->laying)
	{
		printf("geting new connect nb - NOT YET LAYING\n");
		env->connect_nb = new;
	}
	else if (new > env->connect_nb)
	{
		printf("connect nb is higher!! time to fork\n");
		env->connect_nb = new;
		ft_fork(env);
	}
	printf("AM STILL LAYING, nb is not yet higher\n");
	env->resp[RESP_VAL]--;
	return (OK);
}

int					ft_read_list(t_env *env, char *buf)
{
	char			*list;
	char			**split;
	char			*sp;

	(void)env;
	list = ft_strsub(buf, 1, ft_strlen(buf) - 3);
	split = ft_strsplit(list, ',');
	sp = ft_strchr(split[0], ' ');
	if (sp[0] && sp[1] && ft_isdigit(sp[1]))/*in case of "linemate, nourriture...*/
	{
		ft_read_inventory(env, split, 0);
		ft_print_inv(env);
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
	printf("BUFFER [%s]\n",line );
	if ((line[0] == 'o') || (line[0] == 'k'))// OK / KO
	{
		if (line[0] == 'k' && env->resp[RESP_OK] == 0 && env->elevating == 1)
			ft_elev_failed(env);
		else
			env->resp[RESP_OK]--;
		printf("OK\n");
		return (OK);
	}
	if (line[0] == '{')// {...}
		return (ft_read_list(env, line));
	if (line[0] == 'e')// elevation en cours
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
	{
		ft_putstr("recevied reply from server I don't understand : '");
		ft_putstr(line);
		ft_putendl("'");
	}
	return (OK);
}

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
}
