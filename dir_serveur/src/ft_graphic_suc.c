/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_suc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:20:58 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 17:23:06 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_suc(t_env *env, int cs)
{
	char			*str;

	(void)env;
	(void)cs;
	str = NULL;
	str = ft_strdup("suc\n");
	return (str);
}
