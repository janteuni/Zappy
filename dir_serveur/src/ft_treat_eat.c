/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 18:36:41 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 12:37:05 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "serveur.h"

static void			st_decrement_nb(t_env *env, char *str)
{
	int				i;

	i = 0;
	while (i < env->max_team)
	{
		if (ft_strcmp(str, env->teams[i].name) == 0)
			env->teams[i].max_player--;
		i++;
	}
}

static void			st_eggs_are_dead(t_env *env)
{
	t_list			*list;

	list = env->eggs;
	while (list)
	{
		((t_egg *)list->content)->life -= 1;
		if (((t_egg *)list->content)->state == BORN
					&& ((t_egg *)list->content)->life <= 0)
		{
			st_decrement_nb(env, ((t_egg *)list->content)->team);
			ft_graphic_reply(env, ((t_egg *)list->content)->num,
					ft_graphic_edi);
			printf("egg die\n");
			ft_del_elem(&env->eggs, list, ft_del_egg);
		}
		list = list->next;
	}
}

void				ft_treat_eat(t_env *env)
{
	int				i;

	i = 0;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			env->fd_socket[i].inventory[FOOD] -= 1;
			if (env->fd_socket[i].inventory[FOOD] <= 0)
			{
				printf("==============  MORT de %d =============\n", i);
				send(i, "mort\n", 5, 0);
				ft_graphic_reply(env, i, ft_graphic_pdi);
				clean_fd(&env->fd_socket[i]);
			}
		}
		i++;
	}
	st_eggs_are_dead(env);
}
