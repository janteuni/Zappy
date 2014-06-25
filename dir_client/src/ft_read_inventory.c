/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_inventory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 21:49:51 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 21:49:54 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

static int			ft_get_nb(char *line)
{
	char			**split;
	int				res;

	split = ft_strsplit(line, ' ');
	res = ft_atoi(split[1]);
	ft_free_tab((void ***)&split);
	return (res);
}

void				ft_read_inventory(t_env *env, char **s, int i)
{
	while (i < INV_SIZE)
	{
		if (!ft_strncmp("nourriture", s[i], 10))
			env->inv[FOOD] = ft_get_nb(s[i]);
		else if (!ft_strncmp(STONE_1, s[i], ft_strlen(STONE_1)))
			env->inv[LINEMATE] = ft_get_nb(s[i]);
		else if (!ft_strncmp(STONE_2, s[i], ft_strlen(STONE_2)))
			env->inv[DERAUMERE] = ft_get_nb(s[i]);
		else if (!ft_strncmp(STONE_3, s[i], ft_strlen(STONE_3)))
			env->inv[SIBUR] = ft_get_nb(s[i]);
		else if (!ft_strncmp(STONE_4, s[i], ft_strlen(STONE_4)))
			env->inv[MENDIANE] = ft_get_nb(s[i]);
		else if (!ft_strncmp(STONE_5, s[i], ft_strlen(STONE_5)))
			env->inv[PHIRAS] = ft_get_nb(s[i]);
		else if (!ft_strncmp(STONE_6, s[i], ft_strlen(STONE_6)))
			env->inv[THYSTAME] = ft_get_nb(s[i]);
		++i;
	}
}
