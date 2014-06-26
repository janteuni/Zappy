/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_ebo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 14:22:59 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:29:17 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char					*ft_graphic_ebo(t_env *env, int cs)
{
	char				*str;

	(void)env;
	asprintf(&str, "ebo #%d\n", cs);
	return (str);
}
