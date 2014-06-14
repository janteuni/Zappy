/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_inventory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 11:36:48 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/14 15:04:34 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

void				ft_treat_inventory(t_env *env, int cs, char *rcv)
{
	int				i;
	char			*ret;
	char			*tmp;
	char			*itoa;

	(void)rcv;
	i = 0;
	ret = ft_strdup("{");
	tmp = NULL;
	itoa = NULL;
	while (i < NB_STUFF)
	{
		tmp = ft_strjoin(ret, env->stuff[i]);
		ft_memdel((void **)&ret);
		ret = ft_strjoin(tmp, " ");
		ft_memdel((void **)&tmp);
		itoa = ft_itoa(env->fd_socket[cs].inventory[i]);
		tmp = ft_strjoin(ret, itoa);
		ft_memdel((void **)&ret);
		ft_memdel((void **)&itoa);
		ret = ft_strjoin(tmp, ", ");
		ft_memdel((void **)&tmp);
		i++;
	}
	ret[ft_strlen(ret) - 1] = '\0';
	ret[ft_strlen(ret) - 1] = '}';
	ft_reply_in_buff(env, cs, ret);
	ft_memdel((void **)&ret);
}
