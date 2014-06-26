/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_sbp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 12:19:21 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 12:21:15 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_sbp(t_env *env, int cs)
{
	char			*ret;

	(void)cs;
	(void)env;
	ret = ft_strdup("sbp\n");
	return (ret);
}
