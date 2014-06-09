/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:51:20 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 10:34:19 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

int					st_wrong_params(void)
{
	ft_putstr_fd("Usage: ./serveur -p <port> -x <width> -y <height> -n ", 2);
	ft_putendl_fd("<team> [<team>] [<team>] ... -c <nb> -t <t>", 2);
	exit (-1);
}

int					st_valid_flag(char *arg)
{
	if (ft_strlen(arg) == 2 && (arg[1] == 'p'
			|| arg[1] == 'x' || arg[1] == 'y' || arg[1] == 'n'
			|| arg[1] == 'c' || arg[1] == 't'))
		return (OK);
	return (ERR);
}

int					all_options_are_set(t_env *env)
{
	if (env->max_team != 0 && env->width != 0 && env->height != 0
			&& env->time != 0 && env->nb_player != 0 && env->port != 0)
		return (OK);
	ft_putstr_fd("All parameters are required", 2);
	ft_putendl_fd("and have to be numeric except team_name", 2);
	return (ERR);
}

int					parser(t_env *env, int argc, char **argv)
{
	int				i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && st_valid_flag(argv[i]) == OK)
			ft_pars_flag(&i, argv, argc, env);
		else
			st_wrong_params();
		i++;
	}
	if (all_options_are_set(env) == OK)
		return (OK);
	return (ERR);
}
