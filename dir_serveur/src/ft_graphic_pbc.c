/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pbc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:55:07 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 16:00:45 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_pbc(t_env *env, int cs, char *msg)
{
	char			*str;

	(void)env;
	asprintf(&str, "pbc %d %s\n", cs, msg);
	return (str);
}
