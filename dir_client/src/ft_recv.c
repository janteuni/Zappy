/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:22:18 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/11 12:33:43 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include "client.h"

/*int					is_dead(t_env *env, char *buf)
{
	if (!ft_strncmp(DEAD, buf, ft_strlen(DEAD)))
	{
		printf("I DIED - %s\n", buf);
		env->dead = 1;
		return (YES);
	}
	else
		return (NO);
}

int					is_move(t_env *env, char *buf)
{
	char			**split;
	int				dir;

	if (!ft_strncmp(MOVE, buf, ft_strlen(MOVE)))
	{
		printf("I WAS MOVED - %s\n", buf);
		dir = ft_atoi(split[1]);
		if (dir == N)
			env->y++;
		if (dir == E)
			env->x--;
		if (dir == S)
			env->y--;
		if (dir == W)
			env->x++;
		ft_free_tab((void ***)&split);
		return (YES);
	}
	return (NO);
}

int					is_msg(t_env *env, char *buf)
{
	if (!ft_strncmp(MSG, buf, ft_strlen(MSG)))
	{
		printf("I GOT A MSG - %s\n", buf);
		ft_treat_msg(env, buf);
		return (YES);
	}
	return (NO);
}

int					is_elev(t_env *env, char *buf)
{
	if (!ft_strncmp(ELEV, buf, ft_strlen(ELEV)))
	{
		printf("I AM BEING ELEVATED - %s\n", buf);
		if (enough_food(env))
			env->elevating = 1;
		return (YES);
	}
	return (NO);
}*/

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
	if (buf[0] == 'o')// OK
	{
		env->resp[RESP_OK]--;
		printf("OK\n");
		return (OK);
	}
	if (buf[0] == 'k') // KO
	{
		env->resp[RESP_OK]--;
		printf("KO\n");
		return (OK);
	}
	if (buf[0] == '{')// {...}
	return (ft_read_list(env, buf));
	/*if (buf[0] == 'e')// elevation en cours
	  return (ft_is_elev(env, buf));
	  if (buf[0] == 'n') // niveau actuel
	  return (ft_end_elev(env, buf));
	  if (buf[0] == 'd') // deplacement <K>
	  return (ft_move(env, buf));
	  if (buf[0] == 'm' && !ft_strncmp(DEAD, buf, ft_strlen(DEAD))) // mort
	  return (ft_dead(env, buf));
	  if (buf[0] == 'm' && !ft_strncmp(MSG, buf, ft_strlen(MSG))) // message <msg>
	  return (ft_message(env, buf));
	  else
	  {
	  ft_putstr("recevied reply from server I don't understand : '");
	  ft_putstr(buf);
	  ft_putendl("'");
	  }*/
	return (OK);
}
