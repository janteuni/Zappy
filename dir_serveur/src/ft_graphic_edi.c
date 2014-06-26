/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_edi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 15:41:14 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:29:10 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char			*ft_graphic_edi(t_env *env, int cs)
{
	char		*str;

	(void)env;
	asprintf(&str, "edi #%d\n", cs);
	return (str);
}
