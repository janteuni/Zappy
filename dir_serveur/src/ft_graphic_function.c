/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 15:37:24 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 17:24:16 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_assign_cmd(t_gr gr[])
{
	gr[0].fn = ft_treat_msz;
	gr[0].name = "msz";
	gr[1].fn = ft_treat_bct;
	gr[1].name = "bct";
	gr[2].fn = ft_treat_mct;
	gr[2].name = "mct";
	gr[3].fn = ft_treat_tna;
	gr[3].name = "tna";
	gr[4].fn = ft_treat_ppo;
	gr[4].name = "ppo";
/*	gr[5].fn = ft_treat_plv;
	gr[5].name = "plv";
	gr[6].fn = ft_treat_pin;
	gr[6].name = "pin";
	gr[7].fn = ft_treat_sgt;
	gr[7].name = "sgt";
	gr[8].fn = ft_treat_sst;
	gr[8].name = "sst";*/
}

int					ft_graphic_function(t_env *env, int cs, char *rcv)
{
	int				i;
	static t_gr		gr[NB_GR];
	char			**split;

	split = NULL;
	(void)env;
	split = ft_super_split(rcv);
	st_assign_cmd(gr);
	i = 0;
	while (i < NB_GR)
	{
		if (0 == ft_strcmp(gr[i].name, split[0]))
		{
			gr[i].fn(env, cs, rcv);
			ft_free_tab((void ***)&split);
			return (OK);
		}
		++i;
	}
	ft_free_tab((void ***)&split);
	return (ERR);
}
