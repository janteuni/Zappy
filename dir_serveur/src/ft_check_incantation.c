/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_incantation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 10:49:51 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/18 15:32:43 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int			st_incantation_succeed(t_env *env, t_pos pos,
		int level, t_list *list)
{
	t_list			*players;
	t_list			*my_list;

	players = ft_get_players_from_case(env, pos);
	my_list = ((t_snapshot *)list->content)->players;
	if (!ft_lst_contains(my_list, players))
	{
		ft_lstdel(&players, ft_del);
		return (ERR);
	}
	ft_lstdel(&players, ft_del);
	if (ft_compare_stuff(env, ((t_snapshot *)list->content)->stuff, level + 1)
			== OK)
		return (OK);
	return (ERR);
}

static void			st_inform_end(t_env *env, t_list *players, int level)
{
	int				cs;
	char			*str;

	while (players)
	{
		cs = (int)(*(int *)players->content);
		if (env->fd_socket[cs].type == CLIENT)
		{
			env->fd_socket[cs].level = level;
			TOTY(cs) = -1;
			TOTX(cs) = -1;
			asprintf(&str, "niveau actuel : %d\n", level);
			ft_reply_in_buff(env, cs, str);
			ft_memdel((void **)&str);
			ft_graphic_reply(env, cs, ft_graphic_plv);
			players = players->next;
		}
	}
}

static void			st_incantation_terminate(t_env *env, t_pos pos,
		int level, t_list *list)
{
	int				result;

	result = NO;
	if (st_incantation_succeed(env, pos, level, list) == OK)
	{
		result = YES;
		level++;
	}
	env->map[pos.y][pos.x][INCANT] = NO;
	ft_graphic_pie(env, pos, result);
	st_inform_end(env, ((t_snapshot *)list->content)->players, level);
	ft_del_elem(&env->elevation, list, ft_del_snapshot);
	ft_reject_stones(env, level, pos);
}

void				ft_check_incantation(t_env *env, int cs, char *rcv)
{
	char			**split;
	t_pos			pos;
	int				level;
	int				result;
	t_list			*list;

	(void)cs;
	split = ft_strsplit(rcv, ' ');
	pos.x = ft_atoi(split[0]);
	pos.y = ft_atoi(split[1]);
	level = ft_atoi(split[2]);
	result = NO;
	list = env->elevation;
	while (list)
	{
		if (((t_snapshot *)list->content)->pos.x == pos.x
				&& ((t_snapshot *)list->content)->pos.y == pos.y)
		{
			st_incantation_terminate(env, pos, level, list);
			break ;
		}
		list = list->next;
	}
	ft_free_tab((void ***)&split);
}
