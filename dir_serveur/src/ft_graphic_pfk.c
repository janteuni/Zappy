/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pfk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:14:08 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 11:24:17 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char					*ft_graphic_pfk(t_env *env, int cs)
{
	char				*str;

	(void)env;
	asprintf(&str, "pfk %d\n", cs);
	return (str);
}
