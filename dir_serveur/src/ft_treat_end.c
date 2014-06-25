/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:09:52 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 16:56:29 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void				st_end_of_game(t_env *env, int i)
{
	t_list				*list;
	int					cs;

	list = env->teams[i].players;
	cs = ((t_player *)list->content)->sock;
	ft_graphic_reply(env, cs, ft_graphic_seg);
	printf("---------------TEAM %s WIN-----------------\n", env->teams[i].name);
}

static int				st_all_players_level_max(t_env *env, int i)
{
	t_list				*list;
	int					nb;
	int					cs;

	nb = 0;
	list = env->teams[i].players;
	while (list)
	{
		cs = ((t_player *)list->content)->sock;
		if (env->fd_socket[cs].type == CLIENT && env->fd_socket[cs].level == 8)
			nb++;
		list = list->next;
	}
	if (nb >= 6)
		return (YES);
	return (NO);
}

int						ft_treat_end(t_env *env)
{
	int					i;

	i = 0;
	while (i < env->max_team)
	{
		if (env->teams[i].nb_player >= 6)
		{
			if (st_all_players_level_max(env, i) == YES)
			{
				st_end_of_game(env, i);
				ft_treat_dead_all(env);
				return (YES);
			}
		}
		i++;
	}
	return (NO);
}
