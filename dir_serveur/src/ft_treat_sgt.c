/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_sgt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 11:06:37 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 11:10:45 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_sgt(t_env *env, int cs, char *rcv)
{
	char			*str;

	str = NULL;
	(void)rcv;
	(void)cs;
	str = ft_graphic_sgt(env);
	if (env->graphic != -1)
		ft_reply_in_buff(env, env->graphic, str);
	ft_memdel((void **)&str);
}
