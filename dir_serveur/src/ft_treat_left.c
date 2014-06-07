/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:52:26 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/07 11:21:11 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_left(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	if (OR(cs) == N)
		OR(cs) = O;
	else if (OR(cs) == O)
		OR(cs) = S;
	else if (OR(cs) == S)
		OR(cs) = E;
	else if (OR(cs) == E)
		OR(cs) = O;
}
