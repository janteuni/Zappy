/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:18:55 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 11:12:14 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void			ft_graphic_pie(t_env *env, int cs, int result)
{
	char		*str;

	if (env->graphic != -1)
	{
		asprintf(&str, "pie %d %d %d\n", TOTX(cs), TOTY(cs), result);
		ft_reply_in_buff(env, env->graphic, str);
		ft_memdel((void **)&str);
	}
}
