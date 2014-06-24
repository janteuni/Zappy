/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 21:48:52 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 21:48:57 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

static int			**ft_malloc_view(t_env *env)
{
	int				i;
	int				nb;

	nb = (env->level + 1) * (env->level + 1);
	i = 0;
	if (env->view)
		ft_free_tab((void ***)&env->view);
	if (!(env->view = (int **)malloc((nb + 1) * sizeof(int *))))
		return (NULL);
	env->view_size = nb;
	env->view[nb] = NULL;
	while (i < nb)
	{
		env->view[i] = (int *)malloc(sizeof(int) * (SEE_SIZE + 1));
		ft_bzero((void *)env->view[i], sizeof(int) * SEE_SIZE);
		++i;
	}
	return (env->view);
}

static void			ft_add_obj(int i, int **view, char *line)
{
	if (!ft_strcmp(line, "nourriture"))
		view[i][FOOD]++;
	else if (!ft_strcmp(line, "linemate"))
		view[i][LINEMATE]++;
	else if (!ft_strcmp(line, "deraumere"))
		view[i][DERAUMERE]++;
	else if (!ft_strcmp(line, "sibur"))
		view[i][SIBUR]++;
	else if (!ft_strcmp(line, "mendiane"))
		view[i][MENDIANE]++;
	else if (!ft_strcmp(line, "phiras"))
		view[i][PHIRAS]++;
	else if (!ft_strcmp(line, "thystame"))
		view[i][THYSTAME]++;
	else if (!ft_strcmp(line, "joueur"))
		view[i][PLAYERS]++;
}

static int			ft_read_square(char *sqr, int i, int **view)
{
	char			**split;
	int				n;

	split = ft_strsplit(sqr, ' ');
	n = 0;
	while (split[n])
	{
		ft_add_obj(i, view, split[n]);
		++n;
	}
	ft_free_tab((void ***)&split);
	return (OK);
}

int					ft_read_view(t_env *env, char **split)
{
	int				i;

	env->view = ft_malloc_view(env);
	i = 0;
	while (split[i])
	{
		ft_read_square(split[i], i, env->view);
		env->view[i][DIST] = (i == 0 ? 0 : ft_calc_dist(i));
		++i;
	}
	return (OK);
}
