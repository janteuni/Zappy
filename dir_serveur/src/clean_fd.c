/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:23:45 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 12:44:20 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static void		st_del_me(t_fd *fd)
{
	t_env		*env;
	t_list		*players;
	int			i;

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
					ft_del_elem(&env->teams[i].players, players);
				players = players->next;
			}
			env->teams[i].nb_player -= 1;

		}
		i++;
	}
}

void	clean_fd(t_fd *fd)
{
	fd->type = FREE;
	fd->my_cs = 0;
	fd->buf_offset = 0;
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	if (fd->my_team)
	{
		st_del_me(fd);
		ft_memdel((void **)&fd->my_team);
	}
	if (fd->line)
		ft_lstdel(&fd->line, ft_del);
	if (fd->line_read)
		ft_lstdel(&fd->line_read, ft_del);
}
