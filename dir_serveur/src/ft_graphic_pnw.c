/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pnw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 18:36:46 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 18:44:02 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

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
	tmp = ft_strjoin(ret, itoa);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&ret);
	ret = ft_strjoin(tmp, " ");
	itoa = ft_itoa(POSY(cs));
	ft_memdel((void **)&tmp);
	tmp = ft_strjoin(ret, itoa);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&ret);
	itoa = ft_itoa(OR(cs));
	ret = ft_strjoin(tmp, itoa);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&tmp);
}
