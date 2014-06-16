/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pbc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:55:07 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:21:02 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_pbc(t_env *env, int cs, char *msg)
{
	char			*str;

	(void)env;
	str = NULL;
	if (cs >= 0 && cs < env->max_fd && env->fd_socket[cs].type == CLIENT)
		asprintf(&str, "pbc #%d %s\n", cs, msg);
	return (str);
}
