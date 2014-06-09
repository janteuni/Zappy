/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_expulse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:05:56 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 15:32:06 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_special_avance(t_env *env, int cs, int or)
{
	t_pos			new_pos;

	new_pos.x = POSX(cs);
	new_pos.y = POSY(cs);
	if (or == N)
		new_pos.y = new_pos.y == 0 ? HEIGHT - 1 : new_pos.y - 1;
	else if (or == S)
		new_pos.y = new_pos.y == HEIGHT - 1 ? 0 : new_pos.y + 1;
	else if (or == O)
		new_pos.x = new_pos.x == 0 ? WIDTH - 1 : new_pos.x - 1;
	else if (or == E)
		new_pos.x = new_pos.x == WIDTH - 1 ? 0 : new_pos.x + 1;
	POSX(cs) = new_pos.x;
	POSY(cs) = new_pos.y;
}

static void			st_inform(t_env *env, int i, int cs)
{
	char			*join;
	char			*itoa;

	join = NULL;
	itoa = NULL;
	if (OR(cs) == N)
		itoa = ft_itoa(S);
	else if (OR(cs) == S)
		itoa = ft_itoa(N);
	else if (OR(cs) == E)
		itoa = ft_itoa(O);
	else if (OR(cs) == O)
		itoa = ft_itoa(E);
	join = ft_strjoin("deplacement ", itoa);
	ft_memdel((void **)&itoa);
	ft_reply_in_buff(env, i, join);
	ft_memdel((void **)&join);
}

void				ft_treat_expulse(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	int				i;
	int				expulse;

	i = 0;
	expulse = 0;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT && i != cs)
		{
			if (POSX(i) == POSX(cs) && POSY(i) == POSY(cs))
			{
				expulse++;
				st_special_avance(env, i, OR(cs));
				st_inform(env, i, cs);
			}
		}
		i++;
	}
	if (expulse == 0)
		ft_messages_add(env, cs, "ko", 7);
	else
		ft_messages_add(env, cs, "ok", 7);
}
