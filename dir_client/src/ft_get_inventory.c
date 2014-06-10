/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 20:58:40 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/10 16:15:07 by fbeck            ###   ########.fr       */
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
		else if (ft_strlen(s[i]) > 8 && !ft_strncmp("linemate", s[i], 8))
			env->inv[LINEMATE] = ft_get_nb(s[i]);
		else if (ft_strlen(s[i]) > 9 && !ft_strncmp("deraumere", s[i], 9))
			env->inv[DERAUMERE] = ft_get_nb(s[i]);
		else if (ft_strlen(s[i]) > 5 && !ft_strncmp("sibur", s[i], 5))
			env->inv[SIBUR] = ft_get_nb(s[i]);
		else if (ft_strlen(s[i]) > 8 && !ft_strncmp("mendiane", s[i], 8))
			env->inv[MENDIANE] = ft_get_nb(s[i]);
		else if (ft_strlen(s[i]) > 6 && !ft_strncmp("phiras", s[i], 6))
			env->inv[PHIRAS] = ft_get_nb(s[i]);
		else if (ft_strlen(s[i]) > 8 && !ft_strncmp("thystame", s[i], 8))
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
	env->cmds[INVENT]++;
	env->replies[SUCCESS] = ft_strdup(LIST);
	env->replies[FAIL] = NULL;
	printf("SEND COMMAND : INVENTORY\n");
	if ((n = send(env->socket, str, ft_strlen(str), 0)) < 0)
		return (error("Failed to send command"));
	return (OK);
}
