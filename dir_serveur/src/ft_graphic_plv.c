/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_plv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:02:58 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 15:10:03 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_plv(t_env *env, int cs)
{
	char		*str;

	asprintf(&str, "plv %d %d\n", cs, env->fd_socket[cs].level);
	return (str);
}
