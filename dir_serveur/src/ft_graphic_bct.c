/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_bct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 16:45:18 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:02:20 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static char			*st_string_case(t_env *env, int x, int y)
{
	char			*ret;
	char			*tmp;
	char			*itoa;
	int				i;
	int				nb;

	i = 0;
	ret = NULL;
	while (i < NB_STUFF)
	{
		nb = env->map[y][x][i];
		itoa = ft_itoa(nb);
		tmp = ft_strjoin(ret, itoa);
		if (ret)
			ft_memdel((void **)&ret);
		ret = ft_strjoin(tmp, " ");
		ft_memdel((void **)&itoa);
		ft_memdel((void **)&tmp);
		i++;
	}
	ret[ft_strlen(ret) - 1] = '\n';
	return (ret);
}

char				*ft_graphic_bct(t_env *env, int x, int y)
{
	char			*ret;
	char			*tmp;
	char			*itoa;

	itoa = ft_itoa(x);
	tmp = ft_strjoin("bct ", itoa);
	ret = ft_strjoin(tmp, " ");
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&tmp);
	itoa = ft_itoa(y);
	tmp = ft_strjoin(ret, itoa);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&ret);
	ret = ft_strjoin(tmp, " ");
	ft_memdel((void **)&tmp);
	itoa = st_string_case(env, x, y);
	tmp = ft_strjoin(ret, itoa);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&ret);
	return (tmp);
}

void				ft_graphic_all_map(t_env *env, int cs)
{
	int				i;
	int				j;
	char			*line;

	i = 0;
	line = NULL;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			line = ft_graphic_bct(env, j, i);
			ft_reply_in_buff(env, cs, line);
			ft_memdel((void **)&line);
			j++;
		}
		i++;
	}
}
