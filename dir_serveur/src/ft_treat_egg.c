/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_egg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:40:17 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 11:54:39 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_egg(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	printf("EGG IS OOOOOOKKKKK\n");
	ft_graphic_reply(env, cs, ft_graphic_eht);
}
