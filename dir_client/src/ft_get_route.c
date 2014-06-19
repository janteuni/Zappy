/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_route.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 16:09:08 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/19 12:02:08 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "client.h"

int					ft_avance(t_env *env, int num)
{
	int				i;

	i = 0;
	while (i < num)
	{
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		++i;
	}
	return (OK);
}

int					ft_get_route(t_env *env, int squ)
{
	int				l;
	int				i;
	int				row_mid;

	i = 0;
/*	l = ft_calc_level(squ);*/
	l = (int)sqrt(squ);
	ft_avance(env, l);
	row_mid = (l * l) + (((l * 2) + 1) / 2);
	if (squ < row_mid)
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
	else if (squ > row_mid)
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
	ft_avance(env, ABS(row_mid, squ));
	return (OK);
}
