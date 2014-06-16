/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_ppo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 15:41:20 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 15:55:21 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void			ft_treat_ppo(t_env *env, int cs, char *rcv)
{
	int			player;
	char		**split;

	split = NULL;
	split = ft_super_split(rcv);
	if (ft_tab_len(split) == 2)
	{
		player = ft_atoi(split[1]);
		if (ft_graphic_reply(env, player, ft_graphic_ppo) == ERR)
		{
			printf("ERR - send message sbp\n");
			ft_graphic_reply(env, cs, ft_graphic_sbp);
		}
	}
	else
		ft_graphic_reply(env, cs, ft_graphic_sbp);
}
