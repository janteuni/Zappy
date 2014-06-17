/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reject_stones.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 13:35:41 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 16:41:49 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "serveur.h"

static void					st_place_stones(t_env *env, int level)
{
	char					*line;
	int						i;
	t_pos					pos;

	i = 1;
	srand(time(0));
	printf("level = %d\n", level);
	while (i < NB_STUFF)
	{
		if (TOTEM[level][i] > 0)
		{
			printf("place stone	\n");
			pos.x = rand() % WIDTH;
			pos.y = rand() % HEIGHT;
			env->map[pos.y][pos.x][i] += TOTEM[level][i];
			line = ft_graphic_bct(env, pos.x, pos.y);
			if (env->graphic != -1)
				ft_reply_in_buff(env, env->graphic, line);
			ft_memdel((void **)&line);
		}
		i++;
	}
}

void						ft_reject_stones(t_env *env, int level, t_pos pos)
{
	char					*line;

	env->map[pos.y][pos.x][LINEMATE] -= TOTEM[level][LINEMATE];
	env->map[pos.y][pos.x][DERAUMERE] -= TOTEM[level][DERAUMERE];
	env->map[pos.y][pos.x][SIBUR] -= TOTEM[level][SIBUR];
	env->map[pos.y][pos.x][MENDIANE] -= TOTEM[level][MENDIANE];
	env->map[pos.y][pos.x][PHIRAS] -= TOTEM[level][PHIRAS];
	env->map[pos.y][pos.x][THYSTAME] -= TOTEM[level][THYSTAME];
	line = ft_graphic_bct(env, pos.x, pos.y);
	if (env->graphic != -1)
		ft_reply_in_buff(env, env->graphic, line);
	ft_memdel((void **)&line);
	st_place_stones(env, level);
}
