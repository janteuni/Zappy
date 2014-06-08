/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_incantation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:45:33 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/08 12:46:32 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void					ft_treat_incantation(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	printf("incantaion not implemented yet.\n");
	ft_reply_in_buff(env, cs, "incantaion not implemented yet.");
}
