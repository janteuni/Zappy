/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 18:37:30 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:43:57 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void					ft_treat_pin(t_env *env, int cs, char *rcv)
{
	int			player;
	char		**split;

	split = NULL;
	split = ft_super_split(rcv);
	if (ft_tab_len(split) == 2
			&& ft_strlen(split[1]) >= 2 && split[1][0] == '#')
	{
		player = ft_atoi(split[1] + 1);
		if (ft_graphic_reply(env, player, ft_graphic_pin) == ERR)
			ft_graphic_reply(env, cs, ft_graphic_sbp);
	}
	else
		ft_graphic_reply(env, cs, ft_graphic_sbp);
}
