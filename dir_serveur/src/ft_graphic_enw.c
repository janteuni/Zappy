/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_enw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:44:36 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 16:37:29 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char					*ft_graphic_enw(t_env *env, int cs, int egg)
{
	char					*str;

	(void)env;
	asprintf(&str, "enw #%d #%d %d %d\n", egg, cs, POSX(cs), POSY(cs));
	return (str);
}
