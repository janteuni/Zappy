/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_egg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:40:17 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/21 15:58:42 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

static t_list		*st_egg_birth(t_env *env, char *rcv)
{
	t_list			*eggs;
	int				egg_num;

	eggs = env->eggs;
	egg_num = ft_atoi(rcv);
	while (eggs)
	{
		if (((t_egg *)eggs->content)->num == egg_num)
		{
			((t_egg *)eggs->content)->state = BORN;
			return (eggs);
		}
		eggs = eggs->next;
	}
	return (NULL);
}

void				ft_treat_egg(t_env *env, int cs, char *rcv)
{
	int				i;
	t_list			*egg;

	i = 0;
	(void)cs;
	egg = NULL;
	egg = st_egg_birth(env, rcv);
	while (i < env->max_team)
	{
		if (ft_strcmp(env->teams[i].name, ((t_egg *)egg->content)->team) == 0)
		{
			env->teams[i].max_player++;
			break ;
		}
		i++;
	}
	ft_graphic_reply(env, ft_atoi(rcv), ft_graphic_eht);
}
