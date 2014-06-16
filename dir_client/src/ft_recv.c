/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:22:18 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/16 19:49:49 by fbeck            ###   ########.fr       */
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
		printf("seeting new connect nb - NOT YET LAYING\n");
		env->connect_nb = new;
	}
	else if (new > env->connect_nb)
	{
		printf("connect nb is higher!! time to fork\n");
		env->connect_nb = new;
		ft_fork(env);
	}
	printf("AM laying, nb is not yet higher\n");
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
	if (ft_isdigit(sp[1]))
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

int					ft_recv(t_env *env)
{
	char			buf[BIG_BUF + 1];

	ft_bzero(buf, BIG_BUF + 1);
	recv(env->socket, buf, BIG_BUF, 0);
	printf("BUFFER [%s]\n",buf );
	if ((buf[0] == 'o') || (buf[0] == 'k'))// OK / KO
	{
		if (buf[0] == 'k' && env->resp[RESP_OK] == 0 && env->elevating == 1)
			ft_elev_failed(env);
		else
			env->resp[RESP_OK]--;
		printf("OK\n");
		return (OK);
	}
	if (buf[0] == '{')// {...}
		return (ft_read_list(env, buf));
	if (buf[0] == 'e')// elevation en cours
		return (ft_begin_elev(env, buf));
	if (buf[0] == 'n') // niveau actuel
		return (ft_end_elev(env, buf));
	if (buf[0] == 'd') // deplacement <K>
		return (ft_move(env, buf));
	if (buf[0] == 'm' && !ft_strncmp(DEAD, buf, ft_strlen(DEAD))) // mort
		return (ft_dead(env, buf));
	if (buf[0] == 'm' && !ft_strncmp(MSG, buf, ft_strlen(MSG))) // message <msg>
		return (ft_message(env, buf));
	if (ft_isdigit(buf[0])) // CONNECT_NB
		return (ft_connect_nb(env, buf));
	else
	{
		ft_putstr("recevied reply from server I don't understand : '");
		ft_putstr(buf);
		ft_putendl("'");
	}
	return (OK);
}
