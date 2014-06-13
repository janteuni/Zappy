/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pgt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:24:45 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 11:26:46 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void					ft_graphic_pgt(t_env *env, int cs, int i)
{
	char				*str;

	if (env->graphic != -1)
	{
		asprintf(&str, "pgt %d %d\n", cs, i);
		ft_reply_in_buff(env, env->graphic, str);
		ft_memdel((void **)&str);
	}
}
