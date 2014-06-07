/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:30:03 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/07 12:29:30 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_assign(t_cmd cmds[])
{
	cmds[0].fn = ft_treat_avance;
	cmds[0].name = "avance";
	cmds[1].fn = ft_treat_left;
	cmds[1].name = "gauche";
	cmds[2].fn = ft_treat_right;
	cmds[2].name = "droite";
	cmds[3].fn = ft_treat_inventory;
	cmds[3].name = "inventaire";
	cmds[4].fn = ft_treat_vision;
	cmds[4].name = "voir";
/*	cmds[5].fn = treat_get;
	cmds[5].name = "prend";
	cmds[6].fn = treat_put;
	cmds[6].name = "pose";
	cmds[7].fn = treat_expulse;
	cmds[7].name = "expulse";
	cmds[8].fn = treat_broadcast;
	cmds[8].name = "broadcast";
	cmds[9].fn = treat_incantation;
	cmds[9].name = "incantation";
	cmds[10].fn = treat_fork;
	cmds[10].name = "fork";
	cmds[11].fn = treat_connect_nbr;
	cmds[11].name = "connect_nbr";*/
}

int					ft_function_cmd(t_env *env, int cs, char *rcv)
{
	int				i;
	static t_cmd	cmds[NB_CMDS];

	st_assign(cmds);
	i = 0;
	while (i < NB_CMDS)
	{
		if (0 == ft_strcmp(cmds[i].name, rcv))
		{
			cmds[i].fn(env, cs, rcv);
			return (OK);
		}
		++i;
	}
	return (ERR);
}
