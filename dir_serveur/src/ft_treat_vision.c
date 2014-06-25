/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_vision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 12:30:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 13:51:29 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static void			st_find_begin(t_pos *pos, int cs, t_env *env, int i)
{
	pos->x = POSX(cs);
	pos->y = POSY(cs);
	if (OR(cs) == N)
	{
		pos->y = pos->y - i < 0 ? HEIGHT - i : pos->y - i;
		pos->x = pos->x - i < 0 ? WIDTH - i : pos->x - i;
		while (pos->y < 0)
			pos->y = HEIGHT - abs(pos->y);
		while (pos->x < 0)
			pos->x = WIDTH - abs(pos->x);
	}
	else if (OR(cs) == S)
	{
		pos->y = pos->y + i > HEIGHT - 1 ? ((pos->y + i) - (HEIGHT - 1)) - 1 : pos->y + i;
		pos->x = pos->x + i > WIDTH - 1 ? ((pos->x + i) - (WIDTH - 1)) - 1 : pos->x + i;
		while (pos->y > HEIGHT - 1)
			pos->y = (pos->y - (HEIGHT - 1)) - 1;
		while (pos->x > WIDTH - 1)
			pos->x = (pos->x - (WIDTH - 1)) - 1;
	}
	else if (OR(cs) == O)
	{
		pos->y = pos->y + i > HEIGHT - 1 ? ((pos->y + i) - (HEIGHT - 1)) - 1 : pos->y + i;
		pos->x = pos->x - i < 0 ? WIDTH - i : pos->x - i;
		while (pos->y > HEIGHT - 1)
			pos->y = (pos->y - (HEIGHT - 1)) - 1;
		while (pos->x < 0)
			pos->x = WIDTH - abs(pos->x);
	}
	else if (OR(cs) == E)
	{
		pos->y = pos->y - i < 0 ? HEIGHT - i : pos->y - i;
		pos->x = pos->x + i > WIDTH - 1 ? ((pos->x + i) - (WIDTH - 1)) - 1 : pos->x + i;
		while (pos->y < 0)
			pos->y = HEIGHT - abs(pos->y);
		while (pos->x > WIDTH - 1)
			pos->x = (pos->x - (WIDTH - 1)) - 1;
	}
}

static t_pos		st_reoriente_pos(t_pos pos_case, t_env *env, int cs)
{
	if (OR(cs) == N)
		pos_case.x = pos_case.x == WIDTH - 1 ? 0 : pos_case.x + 1;
	else if (OR(cs) == E)
		pos_case.y = pos_case.y == HEIGHT - 1 ? 0 : pos_case.y + 1;
	else if (OR(cs) == S)
		pos_case.x = pos_case.x == 0 ? WIDTH - 1 : pos_case.x - 1;
	else if (OR(cs) == O)
		pos_case.y = pos_case.y == 0 ? HEIGHT - 1 : pos_case.y - 1;
	return (pos_case);
}

void				st_reply_final_str(t_env *env, int cs, char *tmp, char *r)
{
	(void)r;
	tmp[ft_strlen(tmp) - 1] = '\0';
	tmp[ft_strlen(tmp) - 1] = '}';
	ft_reply_in_buff(env, cs, tmp);
	ft_memdel((void **)&tmp);
}

static void			st_loop(t_env *env, int cs, t_pos *pos_case, char **tmp)
{
	char			*carre;
	char			*final;

	carre = NULL;
	final = NULL;
	if ((carre = ft_list_case(*pos_case, env, cs, 0)) != NULL)
	{
		asprintf(&final, "%s%s, ", *tmp, carre);
		ft_memdel((void **)&carre);
	}
	else
		asprintf(&final, "%s, ", *tmp);
	ft_memdel((void **)tmp);
	*tmp = final;
	*pos_case = st_reoriente_pos(*pos_case, env, cs);
}

void				ft_treat_vision(t_env *env, int cs, char *rcv)
{
	t_pos			pos_case;
	int				i;
	int				j;
	char			*tmp;

	i = 0;
	tmp = ft_strdup("{ ");
	while (i <= LEVEL(cs))
	{
		st_find_begin(&pos_case, cs, env, i);
		j = -1;
		while (++j < (i * 2) + 1)
			st_loop(env, cs, &pos_case, &tmp);
		i++;
	}
	st_reply_final_str(env, cs, tmp, rcv);
}
