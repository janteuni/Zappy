/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:18:55 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/14 13:33:19 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void			ft_graphic_pie(t_env *env, t_pos pos, int result)
{
	char		*str;

	if (env->graphic != -1)
	{
		asprintf(&str, "pie %d %d %d\n", pos.x, pos.y, result);
		ft_reply_in_buff(env, env->graphic, str);
		ft_memdel((void **)&str);
	}
}
