/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_ppo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:42:21 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 14:25:25 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static char			*st_join(char *tmp, char *itoa)
{
	char			*ret;

	ret = NULL;
	ret = ft_strjoin(tmp, itoa);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&tmp);
	return (ret);
}

char				*ft_graphic_ppo(t_env *env, int cs)
{
	char			*ret;
	char			*itoa;
	char			*tmp;

	itoa = NULL;
	ret = NULL;
	tmp = NULL;
	itoa = ft_itoa(cs);
	ret = ft_strjoin("ppo ", itoa);
	tmp = ft_strjoin(ret, " ");
	ft_memdel((void **)&ret);
	ft_memdel((void **)&itoa);
	itoa = ft_itoa(POSX(cs));
	ret = st_join(tmp, itoa);
	tmp = ft_strjoin(ret, " ");
	ft_memdel((void **)&ret);
	itoa = ft_itoa(POSY(cs));
	ret = st_join(tmp, itoa);
	tmp = ft_strjoin(ret, " ");
	ft_memdel((void **)&ret);
	itoa = ft_itoa(OR(cs));
	ret = st_join(tmp, itoa);
	return (ret);
}
