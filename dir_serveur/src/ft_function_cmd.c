/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:30:03 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 12:57:51 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_assign(t_cmd cmds[])
{
	cmds[0].fn = ft_treat_avance;
	cmds[0].name = "avance";
	cmds[0].t = 7;
	cmds[1].fn = ft_treat_left;
	cmds[1].name = "gauche";
	cmds[1].t = 7;
	cmds[2].fn = ft_treat_right;
	cmds[2].name = "droite";
	cmds[2].t = 7;
	cmds[3].fn = ft_treat_inventory;
	cmds[3].name = "inventaire";
	cmds[3].t = 7;
	cmds[4].fn = ft_treat_vision;
	cmds[4].name = "voir";
	cmds[4].t = 7;
	cmds[5].fn = ft_treat_get;
	cmds[5].name = "prend";
	cmds[5].t = 7;
	cmds[6].fn = ft_treat_put;
	cmds[6].name = "pose";
	cmds[5].t = 7;
	cmds[7].fn = ft_treat_expulse;
	cmds[7].name = "expulse";
	cmds[7].t = 7;
	cmds[8].fn = ft_treat_broadcast;
	cmds[8].name = "broadcast";
	cmds[8].t = 7;
	cmds[9].fn = ft_treat_incantation;
	cmds[9].name = "incantation";
	cmds[9].t = 300;
	cmds[10].fn = ft_treat_fork;
	cmds[10].name = "fork";
	cmds[10].t = 42;
	cmds[11].fn = ft_treat_connect_nbr;
	cmds[11].name = "connect_nbr";
	cmds[11].t = 1;
}

int					ft_function_cmd(t_env *env, int cs, char *rcv)
{
	int				i;
	static t_cmd	cmds[NB_CMDS];
	char			**split;

	split = NULL;
	(void)env;
	split = ft_super_split(rcv);
	st_assign(cmds);
	i = 0;
	while (i < NB_CMDS)
	{
		if (0 == ft_strcmp(cmds[i].name, split[0]))
		{
			if (i == 9)
				cmds[i].fn(env, cs, rcv);
			else
				ft_action_add(cs, cmds[i].t, cmds[i].fn, rcv);
			ft_free_tab((void ***)&split);
			return (OK);
		}
		++i;
	}
	ft_free_tab((void ***)&split);
	return (ERR);
}
