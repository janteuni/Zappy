/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_seg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:05:30 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/14 15:07:23 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char							*ft_graphic_seg(t_env *env, int cs)
{
	char				*str;

	asprintf(&str, "seg %s\n", env->fd_socket[cs].my_team);
	return (str);
}
