/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 17:54:45 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 16:37:03 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

t_list				*ft_get_players_from_case(t_env *env, t_pos pos)
{
	t_list			*list;
	int				i;

	i = 0;
	list = NULL;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			if (POSY(i) == pos.y && POSX(i) == pos.x)
				ft_lstpush(&list, ft_lstnew(&i, sizeof(int)));
		}
		i++;
	}
	return (list);
}

t_list				*ft_get_players(t_env *env, int cs)
{
	t_list			*list;
	int				i;

	i = 0;
	list = NULL;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			if (POSY(i) == POSY(cs) && POSX(i) == POSX(cs))
				ft_lstpush(&list, ft_lstnew(&i, sizeof(int)));
		}
		i++;
	}
	return (list);
}

t_list				*ft_get_players_same_level(t_env *env, int cs)
{
	t_list			*list;
	int				i;

	i = 0;
	list = NULL;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			if (POSY(i) == POSY(cs) && POSX(i) == POSX(cs)
					&& env->fd_socket[i].level == env->fd_socket[cs].level)
			{
				ft_lstpush(&list, ft_lstnew(&i, sizeof(int)));
			}
		}
		i++;
	}
	return (list);
}
