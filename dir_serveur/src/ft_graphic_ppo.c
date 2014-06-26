/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_ppo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:42:21 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:20:07 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_ppo(t_env *env, int cs)
{
	char			*str;

	str = NULL;
	if (cs >= 0 && cs < env->max_fd && env->fd_socket[cs].type == CLIENT)
		asprintf(&str, "ppo #%d %d %d %d\n", cs, POSX(cs), POSY(cs), OR(cs));
	return (str);
}
