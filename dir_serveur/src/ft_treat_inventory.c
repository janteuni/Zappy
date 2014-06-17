/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_inventory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 11:36:48 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 17:00:30 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

void				ft_treat_inventory(t_env *env, int cs, char *rcv)
{
	int				i;
	char			*ret;
	char			*tmp;

	(void)rcv;
	i = 0;
	ret = ft_strdup("{");
	tmp = NULL;
	while (i < NB_STUFF)
	{
		asprintf(&tmp, "%s%s %d, ",ret, env->stuff[i],
				env->fd_socket[cs].inventory[i]);
		ft_memdel((void **)&ret);
		ret = tmp;;
		i++;
	}
	ret[ft_strlen(ret) - 1] = '\0';
	ret[ft_strlen(ret) - 1] = '}';
	ft_reply_in_buff(env, cs, ret);
	ft_memdel((void **)&ret);
}
