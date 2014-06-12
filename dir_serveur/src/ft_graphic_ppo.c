/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_ppo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:42:21 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 15:02:17 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_ppo(t_env *env, int cs)
{
	char			*str;

	asprintf(&str, "ppo %d %d %d %d\n", cs, POSX(cs), POSY(cs), OR(cs));
	return (str);
}
