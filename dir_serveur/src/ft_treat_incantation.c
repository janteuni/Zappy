/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_incantation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:45:33 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/08 16:35:58 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int				st_count_players(t_pos pos, t_env *env, int cs, int level)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			if (POSY(i) == pos.y && POSX(i) == pos.x
					&& env->fd_socket[i].level == level)
				j++;
		}
		i++;
	}
	return (j);
}

static void				st_get_infos(t_pos pos, t_env *env, int cs, int tab[NB_STUFF])
{
	int				i;
	int				nb;

	i = 1;
	tab[PLAYERS] = st_count_players(pos, env, cs, env->fd_socket[cs].level);
	while (i < NB_STUFF)
	{
		nb = env->map[pos.y][pos.x][i];
		tab[i] = nb;
		i++;
	}
}

static int				st_compare_stuff(t_env *env, int tab[NB_STUFF], int level)
{
	if (tab[PLAYERS] >= TOTEM[level][PLAYERS]
			&& tab[LINEMATE] >= TOTEM[level][LINEMATE]
			&& tab[DERAUMERE] >= TOTEM[level][DERAUMERE]
			&& tab[SIBUR] >= TOTEM[level][SIBUR]
			&& tab[MENDIANE] >= TOTEM[level][MENDIANE]
			&& tab[PHIRAS] >= TOTEM[level][PHIRAS]
			&& tab[THYSTAME] >= TOTEM[level][THYSTAME])
		return (OK);
	return (ERR);
}

void					ft_treat_incantation(t_env *env, int cs, char *rcv)
{
	int					tab_case[NB_STUFF];

	(void)rcv;
	st_get_infos(env->fd_socket[cs].pos, env, cs, tab_case);
	if (st_compare_stuff(env, tab_case, env->fd_socket[cs].level) == OK)
	{
		ft_reply_in_buff(env, cs, "elevation en cours");
		env->fd_socket[fd].level += 1;
	}
	else
		ft_reply_in_buff(env, cs, "ko");

}
