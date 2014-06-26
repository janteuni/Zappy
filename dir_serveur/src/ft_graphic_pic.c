/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:01:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:26:17 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_pic(t_env *env, int cs)
{
	char			*str;
	char			*tmp;
	int				i;

	i = 0;
	asprintf(&str, "pic %d %d %d #%d", POSX(cs), POSY(cs),
			env->fd_socket[cs].level, cs);
	while (i < env->max_fd)
	{
		if (i != cs && env->fd_socket[i].type == CLIENT && POSY(i) == POSY(cs)
				&& POSX(i) == POSX(cs)
				&& env->fd_socket[i].level == env->fd_socket[cs].level)
		{
			asprintf(&tmp, "%s #%d", str, i);
			ft_memdel((void **)&str);
			str = tmp;
		}
		i++;
	}
	return (str);
}
