/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_incantation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:45:33 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/20 17:57:03 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int		st_count(t_pos pos, t_env *env, int level)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			if (POSY(i) == pos.y && POSX(i) == pos.x
					&& env->fd_socket[i].level == level)
			{
				j++;
			}
		}
		i++;
	}
	return (j);
}

static void		st_get_infos(t_pos pos, t_env *env, int cs, int tab[NB_STUFF])
{
	int			i;
	int			nb;

	i = 1;
	tab[PLAYERS] = st_count(pos, env, env->fd_socket[cs].level);
	while (i < NB_STUFF)
	{
		nb = env->map[pos.y][pos.x][i];
		tab[i] = nb;
		i++;
	}
}

int				ft_compare_stuff(t_env *env, int tab[NB_STUFF], int level)
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

static void		st_reply_echec(t_env *env, int cs)
{
	char			*str;

	asprintf(&str, "niveau actuel : %d\n",env->fd_socket[cs].level);
	ft_reply_in_buff(env, cs, str);
	ft_memdel((void **)&str);
}

void			ft_treat_incantation(t_env *env, int cs, char *rcv)
{
	int			tab_case[NB_STUFF];

	(void)rcv;
	st_get_infos(env->fd_socket[cs].pos, env, cs, tab_case);
	printf("INCANTATION\n PLAYER %d LEVEL %d\n INCANTATION %d \n value of my pos_incantation x:%d y:%d\n", cs, env->fd_socket[cs].level, env->map[POSY(cs)][POSX(cs)][INCANT], TOTX(cs), TOTY(cs));
	printf("CASE %d %d :\nplayers: [%d]\nlinemate: [%d]\nderaumere: [%d]\nsibur: [%d]\nmendiane: [%d]\nphiras: [%d]\nthystame: [%d]\n", POSX(cs), POSY(cs), tab_case[PLAYERS], tab_case[LINEMATE], tab_case[DERAUMERE], tab_case[SIBUR], tab_case[MENDIANE], tab_case[PHIRAS], tab_case[THYSTAME]);
	if (env->fd_socket[cs].level < 8 &&
			env->map[POSY(cs)][POSX(cs)][INCANT] == NO
			&& TOTX(cs) == -1 && TOTY(cs) == -1
			&& ft_compare_stuff(env, tab_case, env->fd_socket[cs].level + 1)
			== OK)
	{
		printf("elevation OK [%d] [%d]\n", POSX(cs), POSY(cs));
		env->map[POSY(cs)][POSX(cs)][INCANT] = YES;
		ft_snapshot(env, cs, tab_case);
		ft_graphic_reply(env, cs, ft_graphic_pic);
	}
	else
	{
		printf("elevation NO\n\n");
		st_reply_echec(env, cs);
	}
}
