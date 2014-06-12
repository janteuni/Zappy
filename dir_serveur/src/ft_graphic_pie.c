/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:18:55 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 17:00:47 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char			*ft_graphic_pie(t_env *env, int cs, int result)
{
	char		*str;

	asprintf(&str, "pie %d %d %d\n", POSX(cs), POSY(cs), result);
	return (str);
}
