/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_connect_nbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 12:15:13 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 15:25:19 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_connect_nbr(t_env *env, int cs, char *rcv)
{
	char			*itoa;
	int				nb;
	int				i;

	(void)rcv;
	nb = 0;
	i = 0;
	while (i < env->max_team)
	{
		if (ft_strcmp(env->teams[i].name, env->fd_socket[cs].my_team) == 0)
			nb = env->teams[i].max_player - env->teams[i].nb_player;
		i++;
	}
	itoa = ft_itoa(nb);
	ft_reply_in_buff(env, cs, itoa);
	ft_memdel((void **)&itoa);
}
