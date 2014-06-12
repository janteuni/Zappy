/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pnw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 18:36:46 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 12:46:19 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static char			*st_join(char *ret, char *itoa)
{
	char			*tmp;

	tmp = NULL;
	tmp = ft_strjoin(ret, itoa);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&ret);
	return (tmp);
}

char				*ft_graphic_pnw(t_env *env, int cs)
{
	char			*ret;
	char			*tmp;
	char			*itoa;

	itoa = ft_itoa(cs);
	tmp = ft_strjoin("pnw ", itoa);
	ft_memdel((void **)&itoa);
	ret = ft_strjoin(tmp, " ");
	ft_memdel((void **)&tmp);
	itoa = ft_itoa(POSX(cs));
	tmp = st_join(ret, itoa);
	ret = ft_strjoin(tmp, " ");
	itoa = ft_itoa(POSY(cs));
	ft_memdel((void **)&tmp);
	tmp = st_join(ret, itoa);
	itoa = ft_itoa(OR(cs));
	ret = ft_strjoin(tmp, " ");
	ft_memdel((void **)&tmp);
	tmp = st_join(ret, itoa);
	ret = ft_strjoin(tmp, " ");
	ft_memdel((void **)&tmp);
	tmp = ft_strjoin(ret, env->fd_socket[cs].my_team);
	ft_memdel((void **)&ret);
	return (tmp);
}
