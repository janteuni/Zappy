/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_eht.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:52:38 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 11:53:16 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_eht(t_env *env, int cs)
{
	char			*str;

	(void )env;
	asprintf(&str, "enw %d\n", cs);
	return (str);
}
