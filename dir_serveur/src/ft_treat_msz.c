/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_msz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 12:06:04 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 12:28:34 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_msz(t_env *env, int cs, char *rcv)
{
	char			*str;

	(void)rcv;
	str = ft_graphic_msz(env);
	ft_reply_in_buff(env, cs, str);
	ft_memdel((void **)&str);
}
