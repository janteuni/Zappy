/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_vision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 12:30:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/14 15:04:20 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void				st_find_begin(t_pos *pos, int cs, t_env *env, int i)
{
	pos->x = POSX(cs);
	pos->y = POSY(cs);
	if (OR(cs) == N)
	{
		pos->y = pos->y - i < 0 ? HEIGHT - i : pos->y - i;
		pos->x = pos->x - i < 0 ? WIDTH - i : pos->x - i;
	}
	else if (OR(cs) == S)
	{
		pos->y = pos->y + i > HEIGHT - 1 ? 0 : pos->y + i;
		pos->x = pos->x + i > WIDTH - 1 ? 0 : pos->x + i;
	}
	else if (OR(cs) == O)
	{
		pos->y = pos->y + i > HEIGHT - 1 ? 0 : pos->y + i;
		pos->x = pos->x - i < 0 ? WIDTH - i : pos->x - i;
	}
	else if (OR(cs) == E)
	{
		pos->y = pos->y - i < 0 ? HEIGHT - i : pos->y - i;
		pos->x = pos->x + i > WIDTH - i ? 0 : pos->x + i;
	}
}

static char			*st_list_player(t_pos pos, t_env *env, int cs, char *final)
{
	char			*ret;
	char			*tmp;
	int				i;

	i = 0;
	tmp = NULL;
	ret = NULL;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT && i != cs)
		{
			if (POSY(i) == pos.y && POSX(i) == pos.x)
			{
				ret = ft_strjoin(tmp, env->fd_socket[i].my_team);
				if (tmp)
					ft_memdel((void **)&tmp);
				tmp = ft_strjoin(ret, " ");
				ft_memdel((void **)&ret);
			}
		}
		i++;
	}
	if (tmp)
	{
		ret = ft_strjoin(final, tmp);
		ft_memdel((void **)&tmp);
	}
	return (ret);
}

static char				*ft_list_case(t_pos pos, t_env *env, int cs)
{
	int				i;
	int				j;
	int				nb;
	char			*ret;
	char			*tmp;

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
	tmp = st_list_player(pos, env, cs, ret);
	if (!tmp)
		tmp = ft_strdup(ret);
	ft_memdel((void **)&ret);
	tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

void				ft_treat_vision(t_env *env, int cs, char *rcv)
{
	t_pos			pos_case;
	int				i;
	int				j;
	char			*carre;
	char			*final;
	char			*tmp;

	i = 0;
	(void)rcv;
	tmp = ft_strdup("{");
	while (i <= LEVEL(cs))
	{
		st_find_begin(&pos_case, cs, env, i);
		j = 0;
		while (j < (i * 2) + 1)
		{
			carre = ft_list_case(pos_case, env, cs);
			final = ft_strjoin(tmp, carre);
			if (tmp)
				ft_memdel((void **)&tmp);
			ft_memdel((void **)&carre);
			tmp = ft_strjoin(final, ", ");
			ft_memdel((void **)&final);
			if (OR(cs) == N)
				pos_case.x = pos_case.x == WIDTH - 1 ? 0 : pos_case.x + 1;
			else if (OR(cs) == E)
				pos_case.y = pos_case.y == HEIGHT - 1 ? 0 : pos_case.y + 1;
			else if (OR(cs) == S)
				pos_case.x = pos_case.x == 0 ? WIDTH - 1 : pos_case.x - 1;
			else if (OR(cs) == O)
				pos_case.y = pos_case.y == 0 ? HEIGHT - 1 : pos_case.y - 1;
			j++;
		}
		i++;
	}
	tmp[ft_strlen(tmp) - 1] = '\0';
	tmp[ft_strlen(tmp) - 1] = '}';
	ft_reply_in_buff(env, cs, tmp);
	ft_memdel((void **)&tmp);
}
