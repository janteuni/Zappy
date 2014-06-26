/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_incantation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 14:44:25 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/24 22:44:47 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

static void				finish_init(t_env *env)
{
	env->incantation[5][SIBUR] = 2;
	env->incantation[5][MENDIANE] = 0;
	env->incantation[5][PHIRAS] = 1;
	env->incantation[5][THYSTAME] = 0;
	env->incantation[6][PLAYERS] = 3;
	env->incantation[6][LINEMATE] = 1;
	env->incantation[6][DERAUMERE] = 2;
	env->incantation[6][SIBUR] = 1;
	env->incantation[6][MENDIANE] = 3;
	env->incantation[6][PHIRAS] = 0;
	env->incantation[6][THYSTAME] = 0;
	env->incantation[7][PLAYERS] = 5;
	env->incantation[7][LINEMATE] = 1;
	env->incantation[7][DERAUMERE] = 2;
	env->incantation[7][SIBUR] = 3;
	env->incantation[7][MENDIANE] = 0;
	env->incantation[7][PHIRAS] = 1;
	env->incantation[7][THYSTAME] = 0;
	env->incantation[8][PLAYERS] = 5;
	env->incantation[8][LINEMATE] = 2;
	env->incantation[8][DERAUMERE] = 2;
	env->incantation[8][SIBUR] = 2;
	env->incantation[8][MENDIANE] = 2;
	env->incantation[8][PHIRAS] = 2;
	env->incantation[8][THYSTAME] = 3;
}

static void				init(t_env *env)
{
	env->incantation[2][PLAYERS] = 0;
	env->incantation[2][LINEMATE] = 1;
	env->incantation[2][DERAUMERE] = 0;
	env->incantation[2][SIBUR] = 0;
	env->incantation[2][MENDIANE] = 0;
	env->incantation[2][PHIRAS] = 0;
	env->incantation[2][THYSTAME] = 0;
	env->incantation[3][PLAYERS] = 1;
	env->incantation[3][LINEMATE] = 1;
	env->incantation[3][DERAUMERE] = 1;
	env->incantation[3][SIBUR] = 1;
	env->incantation[3][MENDIANE] = 0;
	env->incantation[3][PHIRAS] = 0;
	env->incantation[3][THYSTAME] = 0;
	env->incantation[4][PLAYERS] = 1;
	env->incantation[4][LINEMATE] = 2;
	env->incantation[4][DERAUMERE] = 0;
	env->incantation[4][SIBUR] = 1;
	env->incantation[4][MENDIANE] = 0;
	env->incantation[4][PHIRAS] = 2;
	env->incantation[4][THYSTAME] = 0;
	env->incantation[5][PLAYERS] = 3;
	env->incantation[5][LINEMATE] = 1;
	env->incantation[5][DERAUMERE] = 1;
	finish_init(env);
}

int						ft_init_incantation(t_env *env)
{
	int					i;

	i = 0;
	env->incantation = NULL;
	if (!(env->incantation = (int **)malloc(sizeof(int *) * NB_LEVEL)))
		return (ERR);
	while (i < NB_LEVEL)
	{
		if (!(env->incantation[i] = (int *)malloc(sizeof(int) * NB_STUFF)))
			return (ERR);
		i++;
	}
	init(env);
	return (OK);
}
