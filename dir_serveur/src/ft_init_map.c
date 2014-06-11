/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:03:00 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 11:50:56 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "serveur.h"

void					ft_init_map(t_env *env)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	srand(time(0));
	if (!(env->map = (int ***)malloc(sizeof(int **) * env->height)))
		ft_exit("malloc error");
	while (i < env->height)
	{
		if (!(env->map[i] = (int **)malloc(sizeof(int *) * env->width)))
			ft_exit("malloc error");
		j = 0;
		while (j < env->width)
		{
			if (!(env->map[i][j] = (int *)malloc(sizeof(int) * 8)))
				ft_exit("error malloc");
			k = 0;
			env->map[i][j][INCANT] = NO;
			while (k < 7)
				env->map[i][j][k++] = rand() % 8;
			j++;
		}
		i++;
	}
}
