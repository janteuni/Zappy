/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 14:26:27 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 16:42:42 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int					st_check_eggs(t_env *env, int cs)
{
	t_list			*eggs;

	eggs = env->eggs;
	while (eggs)
	{
		if (((t_egg *)eggs->content)->state == BORN
				&& ft_strcmp(env->fd_socket[cs].my_team,
					((t_egg *)eggs->content)->team) == 0)
		{
			printf("assignation : x: %d y:%d\n",
					((t_egg *)eggs->content)->pos.x,
					((t_egg *)eggs->content)->pos.y);
			POSX(cs) = ((t_egg *)eggs->content)->pos.x;
			POSY(cs) = ((t_egg *)eggs->content)->pos.y;
			OR(cs) = ((t_egg *)eggs->content)->pos.o;
			ft_graphic_reply(env, ((t_egg *)eggs->content)->num,
					ft_graphic_ebo);
			ft_del_elem(&env->eggs, eggs, ft_del_egg);
			return (YES);
		}
		eggs = eggs->next;
	}
	return (NO);
}

static void			st_first_response(t_env *env, int cs)
{
	char			*str;
	int				nb;

	nb = ft_calcul_nb(env, cs);
	asprintf(&str, "%d\n%d %d\n", nb, POSX(cs), POSY(cs));
	ft_reply_in_buff(env, cs, str);
	ft_memdel((void **)&str);
}

void				ft_treat_cmd(char *rcv, t_env *env, int cs)
{
	printf(" SERVER RECEIVE CMD: %s\n", rcv);
	if (env->fd_socket[cs].type == GRAPHIC)
	{
		if (ft_graphic_function(env, cs, rcv) == ERR)
			ft_graphic_reply(env, cs, ft_graphic_suc);
	}
	else if (env->fd_socket[cs].my_team == NULL)
	{
		if (ft_strcmp(rcv, "GRAPHIC") == 0)
		{
			if (env->graphic == -1)
				ft_graphic_init(env, cs);
			else
				ft_reply_in_buff(env, cs, "ko");
		}
		else if (ft_add_me_team(env, cs, rcv) == OK)
		{
			if (st_check_eggs(env, cs) == NO)
				ft_place_me(env, cs);
			st_first_response(env, cs);
			ft_graphic_reply(env, cs, ft_graphic_pnw);
		}
	}
	else if (ft_function_cmd(env, cs, rcv) == ERR)
		ft_reply_in_buff(env, cs, "ko");
}
