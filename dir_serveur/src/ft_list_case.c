/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 17:01:06 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 17:03:34 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static char			*st_list_player(t_pos pos, t_env *env, int cs, char **final)
{
	char			*ret;
	char			*tmp;
	int				i;

	i = 0;
	tmp = *final;
	ret = NULL;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT && i != cs)
		{
			if (POSY(i) == pos.y && POSX(i) == pos.x)
			{
				asprintf(&ret, "%sjoueur \n", tmp);
				if (tmp)
					ft_memdel((void **)&tmp);
				tmp = ret;
			}
		}
		i++;
	}
	return (tmp);
}

char				*ft_list_case(t_pos pos, t_env *env, int cs, int i)
{
	int				j;
	int				nb;
	char			*ret;
	char			*tmp;

	ret = NULL;
	tmp = NULL;
	while (i < NB_STUFF)
	{
		nb = env->map[pos.y][pos.x][i];
		j = 0;
		while (j < nb)
		{
			tmp = ft_strjoin(ret, env->stuff[i]);
			ft_memdel((void **)&ret);
			ret = ft_strjoin(tmp, " ");
			ft_memdel((void **)&tmp);
			j++;
		}
		i++;
	}
	tmp = st_list_player(pos, env, cs, &ret);
	tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}
