/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_players_in_team.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 14:57:46 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 15:09:28 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_max_players_in_team(t_env *env)
{
	int				i;

	i = 0;
	printf(" === %d\n", env->max_team);
	while (i < env->max_team)
	{
		env->teams[i].max_player = env->nb_player;
		i++;
	}
}
