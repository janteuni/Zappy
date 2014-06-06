/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 12:10:03 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/06 18:48:57 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

int				st_fill_team(char **argv, int argc, t_env *env, int *i)
{
	int			x;
	int			count;

	x = *i;
	while (x + 1 < argc && argv[x + 1][0] != '-')
	{
		env->max_team++;
		x++;
	}
	env->teams = (t_team *)malloc(sizeof(*env->teams) * (env->max_team));
	if (!env->teams)
		ft_exit("malloc error");
	count = 0;
	while ((*i) + 1 < argc && argv[(*i) + 1][0] != '-')
	{
		env->teams[count].name = ft_strdup(argv[(*i) + 1]);
		env->teams[count].nb_player = 0;
		env->teams[count].players = NULL;
		count++;
		(*i)++;
	}
	return (OK);
}

int				ft_pars_flag(int *i, char **argv, int argc, t_env *env)
{
	int			plus;

	plus = 0;
	if (argc == (*i) + 1)
		return (ft_exit("Invalid."));
	if (argv[*i][1] == 'p')
		env->port = ft_atoi(argv[(*i) + 1]);
	if (argv[*i][1] == 'x')
		env->width = ft_atoi(argv[(*i) + 1]);
	if (argv[*i][1] == 'y')
		env->height = ft_atoi(argv[(*i) + 1]);
	if (argv[*i][1] == 't')
		env->time = ft_atoi(argv[(*i) + 1]);
	if (argv[*i][1] == 'c')
		env->nb_player = ft_atoi(argv[(*i) + 1]);
	if (argv[*i][1] == 'n')
	{
		plus = -1;
		st_fill_team(argv, argc, env, i);
	}
	if (plus == 0)
		(*i)++;
	return (OK);
}
