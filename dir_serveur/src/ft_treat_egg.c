/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_egg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:40:17 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 15:10:28 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

static void			st_egg_birth(t_env *env, char *rcv)
{
	t_list			*eggs;
	long int		tstmp;
	struct timeval	tv;
	int				egg_num;

	eggs = env->eggs;
	egg_num = ft_atoi(rcv);
	gettimeofday(&tv, NULL);
	tstmp = (1000000 * tv.tv_sec + tv.tv_usec);
	while (eggs)
	{
		if (((t_egg *)eggs->content)->num == egg_num)
		{
			printf("EGG %d STATE %d\n", ((t_egg *)eggs->content)->num, ((t_egg *)eggs->content)->state );
			((t_egg *)eggs->content)->state = BORN;
			((t_egg *)eggs->content)->birth = tstmp;
			printf("EGG %d STATE %d\n", ((t_egg *)eggs->content)->num, ((t_egg *)eggs->content)->state );
			break ;
		}
		eggs = eggs->next;
	}
}

void				ft_treat_egg(t_env *env, int cs, char *rcv)
{
	int				i;

	i = 0;
	printf("EGG IS OOOOOOKKKKK\n");
	while (i < env->max_team)
	{
		if (ft_strcmp(env->teams[i].name, env->fd_socket[cs].my_team) == 0)
		{
			env->teams[i].max_player++;
			break ;
		}
		i++;
	}
	st_egg_birth(env, rcv);
	ft_graphic_reply(env, ft_atoi(rcv), ft_graphic_eht);
}
