/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:23:45 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 16:26:51 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static void			st_check_max_player(t_env *env, int i)
{
	int				nb;

	nb = env->teams[i].max_player;
	if (nb > env->nb_player)
		env->teams[i].max_player--;
}

static void			st_del_me(t_fd *fd)
{
	t_env			*env;
	t_list			*players;
	int				i;

	env = get_env();
	i = 0;
	while (i < env->max_team)
	{
		if (ft_strcmp(env->teams[i].name, fd->my_team) == 0)
		{
			players = env->teams[i].players;
			while (players != NULL)
			{
				if (((t_player *)players->content)->sock == fd->my_cs)
					ft_del_elem(&env->teams[i].players, players, ft_del);
				players = players->next;
			}
			env->teams[i].nb_player -= 1;
			st_check_max_player(env, i);
		}
		i++;
	}
}

static void			st_del_action(t_fd *fd)
{
	t_env			*env;
	t_list			*act;

	env = get_env();
	act = env->actions;
	if (fd->type == GRAPHIC)
		env->graphic = -1;
	if (act)
	{
		while (act != NULL)
		{
			if (((t_action *)act->content)->cs == fd->my_cs)
				ft_del_elem(&env->actions, act, ft_del_action);
			act = act->next;
		}
	}
}

static void			st_empty_bag(t_fd *fd)
{
	t_env		*env;
	int			i;
	int			nb;

	env = get_env();
	i = 0;
	if (fd->my_cs == env->graphic)
		return ;
	while (i < NB_STUFF)
	{
		if ((nb = fd->inventory[i]) > 0)
			env->map[fd->pos.y][fd->pos.x][i] += nb;
		i++;
	}
}

void				clean_fd(t_fd *fd)
{
	st_empty_bag(fd);
	if (fd->my_team)
	{
		st_del_me(fd);
		ft_memdel((void **)&fd->my_team);
	}
	if (fd->line)
		ft_lstdel(&fd->line, ft_del);
	if (fd->line_read)
		ft_lstdel(&fd->line_read, ft_del);
	st_del_action(fd);
	fd->type = FREE;
	fd->my_cs = 0;
	fd->buf_offset = 0;
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	ft_bzero(fd->buf_read, BUF_SIZE);
	ft_bzero(fd->buf_write, BUF_SIZE);
}
