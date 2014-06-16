/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:28:02 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:18:23 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_pex(t_env *env, int cs)
{
	char			*str;

	(void)env;
	str = NULL;
	if (cs >= 0 && cs < env->max_fd && env->fd_socket[cs].type == CLIENT)
		asprintf(&str, "pex %d\n", cs);
	return (str);
}
