/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pnw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 18:36:46 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:19:54 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_pnw(t_env *env, int cs)
{
	char			*str;

	asprintf(&str, "pnw #%d %d %d %d %d %s\n", cs, POSX(cs), POSY(cs), OR(cs),
			env->fd_socket[cs].level, env->fd_socket[cs].my_team);
	return (str);
}
