/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_tna.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 17:29:51 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 18:36:06 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char					*ft_graphic_tna(t_env *env)
{
	char				*ret;
	char				*tmp;
	int					i;

	i = 0;
	ret = NULL;
	while (i < env->max_team)
	{
		tmp = ft_strjoin(ret, "tna ");
		if (ret)
			ft_memdel((void **)&ret);
		ret = ft_strjoin(tmp, env->teams[i].name);
		ft_memdel((void **)&tmp);
		tmp = ft_strjoin(ret, "\n");
		ft_memdel((void **)&ret);
		ret = tmp;
		i++;
	}
	return (ret);
}
