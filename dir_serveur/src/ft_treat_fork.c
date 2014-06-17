/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 12:10:25 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 16:47:43 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "serveur.h"

static t_egg			st_fill_egg(t_env *env, int cs)
{
	t_egg				new_egg;

	srand(time(0));
	new_egg.num = env->count_egg;
	new_egg.state = GESTATION;
	new_egg.father = cs;
	new_egg.life = 10;
	new_egg.pos.x = POSX(cs);
	new_egg.pos.y = POSY(cs);
	new_egg.pos.o = rand() % 4;
	if (new_egg.pos.o < 1)
		new_egg.pos.o = 1;
	new_egg.team = ft_strdup(env->fd_socket[cs].my_team);
	return (new_egg);
}

void				ft_treat_fork(t_env *env, int cs, char *rcv)
{
	t_egg			new_egg;
	char			*line;
	char			*itoa;

	(void)rcv;
	line = NULL;
	env->count_egg += 1;
	itoa = ft_itoa(env->count_egg);
	ft_action_tm(-1, 600, ft_treat_egg, itoa);
	ft_memdel((void **)&itoa);
	new_egg = st_fill_egg(env, cs);
	ft_lstpush(&env->eggs, ft_lstnew(&new_egg, sizeof(new_egg)));
	line = ft_graphic_enw(env, cs, env->count_egg);
	if (env->graphic != -1)
		ft_reply_in_buff(env, env->graphic, line);
	ft_memdel((void **)&line);
	printf("x: %d y: %d\n", new_egg.pos.x, new_egg.pos.y);
	ft_reply_in_buff(env, cs, "ok");
}
