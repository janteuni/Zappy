/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_tna.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 12:39:59 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 15:33:23 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_tna(t_env *env, int cs, char *rcv)
{
	char			*str;

	(void)rcv;
	(void)cs;
	str = ft_graphic_tna(env);
	if (env->graphic != -1)
		ft_reply_in_buff(env, env->graphic, str);
	ft_memdel((void **)&str);
}
