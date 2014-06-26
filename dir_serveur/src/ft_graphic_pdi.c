/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pdi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:28:44 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:28:27 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char					*ft_graphic_pdi(t_env *env, int cs)
{
	char			*str;

	(void)env;
	str = NULL;
	if (cs >= 0 && cs < env->max_fd && env->fd_socket[cs].type == CLIENT)
		asprintf(&str, "pdi #%d\n", cs);
	return (str);
}
