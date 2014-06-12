/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:28:02 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 15:41:15 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_pex(t_env *env, int cs)
{
	char			*str;

	(void)env;
	asprintf(&str, "pex %d\n", cs);
	return (str);
}
