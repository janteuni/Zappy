/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_incantation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 10:49:51 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 10:20:00 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int					st_incantation_succeed(t_env *env, int cs)
{
	t_list					*players;
	t_list					*my_list;

	if (POSX(cs) != TOTX(cs) && POSY(cs) != TOTY(cs))
		return (ERR);
	players = ft_get_players(env, cs);
	my_list = env->fd_socket[cs].snapshot.players;
	if (!ft_lst_contains(my_list, players))
	{
		ft_lstdel(&players, ft_del);
		return (ERR);
	}
	ft_lstdel(&players, ft_del);
	if (ft_compare_stuff(env, env->fd_socket[cs].snapshot.stuff, env->fd_socket[cs].level + 1) == OK)
		return (OK);
	return (ERR);
}

void						ft_check_incantation(t_env *env, int cs, char *rcv)
{
	char			*itoa;
	char			*join;

	(void)rcv;
	if (st_incantation_succeed(env, cs) == OK)
		env->fd_socket[cs].level += 1;
	itoa = ft_itoa(env->fd_socket[cs].level);
	join = ft_strjoin("niveau ", itoa);
	env->map[TOTY(cs)][TOTX(cs)][INCANT] = NO;
	TOTY(cs) = -1;
	TOTX(cs) = -1;
	ft_reply_in_buff(env, cs, join);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&join);
	ft_lstdel(&env->fd_socket[cs].snapshot.players, ft_del);
	ft_graphic_reply(env, cs, ft_graphic_plv);
}
