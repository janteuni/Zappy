/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 20:58:40 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/07 21:02:25 by fbeck            ###   ########.fr       */
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

static void			ft_read_inventory(t_env *env, char **s, int i)
{
	while (i < INV_SIZE)
	{
		if (!ft_strncmp("food", s[i], 4))
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
	char			**split;

	ft_bzero(buf, INV_BUF + 1);
	str = ft_strjoin("inventaire", "\n");
	if ((n = send(env->socket, str, ft_strlen(str), 0)) < 0)
		return (error("Failed to send command"));
	recv(env->socket, buf, INV_BUF, 0);
	printf("%s\n", buf);
	split = ft_strsplit(buf, ',');
	ft_read_inventory(env, split, 0);
	ft_free_tab((void ***)&split);
	ft_strdel(&str);
	return (OK);
}

