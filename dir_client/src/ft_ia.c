/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:00:55 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/18 18:16:42 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "client.h"

/*int                 ft_place_random(t_env *env)
{
    int             rand_x;
    int             rand_y;

    rand_x = -1;
    rand_y = -1;
    srand(time(NULL));
    while ((rand_x < 0 && rand_y < 0) || BOARD[rand_y][rand_x] != 0)
    {
        rand_x = rand() % WIDTH;
        rand_y = rand() % HEIGHT;
    }
    BOARD[rand_y][rand_x] = (char)env->team;
    env->posx = rand_x;
    env->posy = rand_y;
    return (0);
}*/

int					ft_random(t_env *env)
{
	int				n;

    srand(time(NULL));
	n = rand() % 8;
	if (n == 1 || n == 0)
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	else if (n < 6)
		ft_dir_left(env, n);
	else
		ft_dir_right(env, n);
	env->dir_chg = 0;
	printf("RANDOM MOVE [%d]\n", n);
	return (OK);
}

int					ft_push_cmd(t_env *env, int cmd_num, char *opt, int resp)
{
	t_cmd			cmd;

	cmd.cmd = ft_strdup(env->cmds[cmd_num]);
	cmd.opt = opt;
	cmd.resp = resp;
	ft_lstpush(&env->moves, ft_lstnew(&cmd, sizeof(t_cmd)));
	return (OK);
}

int					ft_take_all(t_env *env)
{
	int				i;

	i = 0;
	while (i < env->view[0][FOOD] && i < 8)
	{
		ft_push_cmd(env, PREND, ft_strdup(ft_get_str(FOOD)), RESP_OK);
		++i;
	}
	return (OK);
}

int					ft_find(t_env *env, int obj)
{
	int				i;
	int				c;

	c = -1;
	i = 1;
	if (env->view[0][obj] == 0)
	{
		while (i < (env->level + 1) * (env->level + 1))
		{
			if (env->view[i][obj] > 0
					&& (c < 0 || env->view[c][DIST] > env->view[i][DIST]))
				c = i;
			++i;
		}
		if (c > 0)
		{
			env->dir_chg = 0;
			ft_get_route(env, c);
		}
		else
		{
			if (env->dir_chg < 4)
			{
				ft_push_cmd(env, DROITE, NULL, RESP_OK);
				env->dir_chg++;
			}
			else
			{
				env->dir_chg = 0;
				ft_random(env);
			}
			return (OK);
		}
	}
	/*	if (obj == FOOD)
		ft_take_all(env);
		else*/
	ft_push_cmd(env, PREND, ft_strdup(ft_get_str(obj)), RESP_OK);
	return (OK);
}

int					ft_ia(t_env *env)
{
	printf("IA IS STARTING\n");
	if (env->laying)
		ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
	if (env->inv[0] < 0)
		ft_push_cmd(env, INVENT, NULL, RESP_INV);
	if (/*!env->forked &&*/ !env->laying)
	{
		printf("current connect_nb = %d\n",env->connect_nb );
		if (env->connect_nb < 0)
			ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
		else if (ft_enough_food(env))
		{
			ft_push_cmd(env, FORK, NULL, RESP_OK);
			env->laying = 1;
		}
		else
			ft_find(env, FOOD);
	}
	/*	else if (env->laying && !env->forked)
		ft_find(env, FOOD);*/
	else if (/*env->forked*/ env->laying && env->inv[FOOD] < 8)
	{
		ft_find(env, FOOD);
	}
	else
	{
		//COLLECT STONES & DO INCANTATION
		if (ft_check_squ_stones(env))
		{
			ft_get_people_here(env);
		}
		else if (ft_check_inv_stones(env))
		{
			ft_putdown_stones(env);
			ft_get_people_here(env);
		}
		else
			ft_find_stones(env);
	}
	ft_push_cmd(env, INVENT, NULL, RESP_INV);
	ft_push_cmd(env, VOIR, NULL, RESP_VIEW);
	return (OK);
}

