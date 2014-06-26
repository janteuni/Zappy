/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 10:30:27 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 17:40:07 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

static void			st_end_of_game(void)
{
	while (1)
	{
	}
}

void				ft_loop(t_env *env)
{
	struct timeval	tv;
	long int		tmp;
	long int		now;

	gettimeofday(&tv, NULL);
	tmp = 1000000 * tv.tv_sec + tv.tv_usec;
	while (1)
	{
		gettimeofday(&tv, NULL);
		init_fd(env);
		do_select(env);
		ft_actions_select(env);
		now = 1000000 * tv.tv_sec + tv.tv_usec;
		if (tmp + ((126 / env->time) * 1000000) <= now)
		{
			ft_treat_eat(env);
			gettimeofday(&tv, NULL);
			tmp = 1000000 * tv.tv_sec + tv.tv_usec;
		}
		ft_treat_end(env);
		check_fd(env);
		if (env->end == YES)
			break ;
	}
	st_end_of_game();
}
