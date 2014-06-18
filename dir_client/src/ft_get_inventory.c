/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 20:58:40 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/18 22:31:59 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

void				ft_print_inv(t_env *env)
{
	int				i;

	i = 0;
	while (i < INV_SIZE)
	{
		printf("INVENTORY[%d] has %d\n",i, env->inv[i] );
		++i;
	}
}

void				ft_print_split(char **s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		printf("s[%d] = (%s)\n",i, s[i]);
		++i;
	}
	printf("END OF SPLIT\n");
}

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

int					ft_get_inventory(t_env *env)
{
	char			buf[INV_BUF + 1];
	char			*str;
	int				n;

	ft_bzero(buf, INV_BUF + 1);
	str = ft_strjoin("inventaire", "\n");
	/*env->cmds[INVENT]++;
	env->replies[FAIL] = NULL;*/
	printf("SEND COMMAND : INVENTORY\n");
	if ((n = send(env->socket, str, ft_strlen(str), 0)) < 0)
		return (error("Failed to send command"));
	env->resp[RESP_INV]++;
	return (OK);
}
