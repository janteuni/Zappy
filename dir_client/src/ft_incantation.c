/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_incantation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:50:07 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/18 15:43:44 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stdio.h"
#include "client.h"

char				*ft_get_str(int obj)
{
	if (obj == LINEMATE)
		return ("linemate\n");
	if (obj == DERAUMERE)
		return ("deraumere\n");
	if (obj == SIBUR)
		return ("sibur\n");
	if (obj == MENDIANE)
		return ("mendiane\n");
	if (obj == PHIRAS)
		return ("phiras\n");
	if (obj == THYSTAME)
		return ("thystame\n");
	if (obj == FOOD)
		return ("nourriture\n");
	printf("YOUVE ASKED ME FOR AN OBJ [%d] THAT DOESNT EXIST\n", obj);
	return (NULL);
}

int					ft_putdown(t_env *env, int stone)
{
	int				i;
	int				diff;

	diff = env->incantation[env->level + 1][stone] - env->view[0][stone];
	i = 0;
	while (i < diff)
	{
		ft_push_cmd(env, POSE, ft_strdup(ft_get_str(stone)), RESP_OK);
		++i;
	}
	return (OK);
}

int					ft_putdown_stones(t_env *env)
{
	ft_putdown(env, LINEMATE);
	ft_putdown(env, DERAUMERE);
	ft_putdown(env, SIBUR);
	ft_putdown(env, MENDIANE);
	ft_putdown(env, PHIRAS);
	ft_putdown(env, THYSTAME);
	return (OK);
}

int					ft_get_people_here(t_env *env)
{
	char			*msg;

	printf("IN FT_GET_PEOPLE\n");
	if (env->view[0][PLAYERS] >= env->incantation[env->level + 1][PLAYERS])
	{
		printf("THERE ARE ENOUGH PLAYERS TO ELEVATE\n");
		ft_push_cmd(env, INCANT, NULL, NO_RESP);
		env->elevating = 1;
	}
	else
	{
		printf("THERE ARE NOT ENOUGH PLAYERS TO ELEVATE - SENDING MESSAGE\n");
		asprintf(&msg, "%s %d\n", env->team, env->level);
		ft_push_cmd(env, BROAD, ft_strdup(msg), RESP_OK);
		free(msg);
	}
	return (OK);
}

