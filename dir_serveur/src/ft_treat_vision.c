/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_vision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 12:30:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/07 15:40:05 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				st_find_begin(t_pos *pos, int cs, t_env *env, int i)
{
	pos->x = POSX(cs);
	pos->y = POSY(cs);
	if (OR(cs) == N)
	{
		pos->y -= i;
		pos->x -= i;
	}
	else if (OR(cs) == S)
	{
		pos->y += i;
		pos->x += i;
	}
	else if (OR(cs) == O)
	{
		pos->y += i;
		pos->x -= i;
	}
	else if (OR(cs) == E)
	{
		pos->y += i;
		pos->x += i;
	}
}

void				ft_list_case(t_pos pos, t_env *env, int cs)
{
	int				i;
	int				j;
	int				nb;
	char			*ret;
	char			*tmp;

	(void)cs;
	i = 0;
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
	printf("%s\n", ret);
}

void				ft_treat_vision(t_env *env, int cs, char *rcv)
{
	t_pos			pos_case;
	int				i;
	int				j;

	i = 0;
	j = 0;
	(void)rcv;
	while (i < LEVEL(cs))
	{
		st_find_begin(&pos_case, cs, env, i);
		while (j < LEVEL(cs) * 2 + 1)
		{
			ft_list_case(pos_case, env, cs);
			if (OR(cs) == N)
				pos_case.x++;
			else if (OR(cs) == E)
				pos_case.y++;
			else if (OR(cs) == S)
				pos_case.x--;
			else if (OR(cs) == O)
				pos_case.y--;
			j++;
		}
		i++;
	}
}
