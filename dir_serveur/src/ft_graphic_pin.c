/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:16:09 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 15:27:43 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char					*ft_graphic_pin(t_env *env, int cs)
{
	char			*str;

	asprintf(&str, "pin %d %d %d %d %d %d %d %d %d %d\n", cs, POSX(cs),
			POSY(cs), INV(cs)[FOOD], INV(cs)[LINEMATE], INV(cs)[DERAUMERE],
			INV(cs)[SIBUR], INV(cs)[MENDIANE], INV(cs)[PHIRAS],
			INV(cs)[THYSTAME]);
	return (str);
}
