/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_mct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 12:30:00 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 12:35:47 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_mct(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	ft_graphic_all_map(env, cs);
}
