/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:32:31 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/11 11:43:55 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

int					**ft_malloc_view(t_env *env)
{
	int				i;
	int				nb;

	nb = (env->level + 1) * (env->level + 1);
	i = 0;
	if (env->view)
		ft_free_tab((void ***)&env->view);
	if (!(env->view = (int **)malloc((nb + 1) * sizeof(int *))))
		return (NULL);
	env->view[nb] = NULL;
	while (i < nb)
	{
		env->view[i] = (int *)malloc(sizeof(int) * (SEE_SIZE + 1));
		ft_bzero((void *)env->view[i], sizeof(int) * SEE_SIZE);
		++i;
	}
	return (env->view);
}

int					ft_read_square(char *sqr, int i, int **view)
{
	char			**split;
	int				n;

	split = ft_strsplit(sqr, ' ');
	n = 0;
	while (split[n])
	{
		if (!ft_strcmp(split[n], "food"))
			view[i][FOOD]++;
		else if (!ft_strcmp(split[n], "linemate"))
			view[i][LINEMATE]++;
		else if (!ft_strcmp(split[n], "deraumere"))
			view[i][DERAUMERE]++;
		else if (!ft_strcmp(split[n], "sibur"))
			view[i][SIBUR]++;
		else if (!ft_strcmp(split[n], "mendiane"))
			view[i][MENDIANE]++;
		else if (!ft_strcmp(split[n], "phiras"))
			view[i][PHIRAS]++;
		else if (!ft_strcmp(split[n], "thystame"))
			view[i][THYSTAME]++;
		else if (!ft_strcmp(split[n], "joueur"))
			view[i][PLAYERS]++;
		++n;
	}
	ft_free_tab((void ***)&split);
	return (OK);
}

void				ft_print_view(t_env *env, int **view)
{
	int				i;
	int				n;
	char			*str;

	i = 0;
	while (i < ((env->level + 1) * (env->level + 1)))
	{
		printf("VIEW SQR %d:\n",i );
		n = 0;
		while (n < SEE_SIZE)
		{
			if (n == 0)
				str = "FOOD";
			else if (n == 1)
				str = "LINEMATE";
			else if (n == 2)
				str = "DERAUMERE";
			else if (n == 3)
				str = "SIBUR";
			else if (n == 4)
				str = "MENDIANE";
			else if (n == 5)
				str = "PHIRAS";
			else if (n == 6)
				str = "THYSTAME";
			else if (n == 7)
				str = "PLAYERS";
			else
				str = "dunno";

			printf("    nb of %-10s [%d]\n",str, view[i][n] );
			++n;
		}
		++i;
	}
}

int					ft_read_view(t_env *env, char **split)
{
	int				i;

	env->view = ft_malloc_view(env);
	i = 0;
	while (split[i])
	{
		ft_read_square(split[i], i, env->view);
		++i;
	}
	ft_print_view(env, env->view);
	return (OK);
}

int					ft_look(t_env *env)
{
	char			buf[BIG_BUF + 1];
	char			*str;
	int				i;

	ft_bzero(buf, BIG_BUF + 1);
	str = ft_strjoin("voir", "\n");
	printf("SEND COMMAND : VOIR\n");
	if ((i = send(env->socket, str, ft_strlen(str), 0)) < 0)
		return (error("Failed to send command"));
	env->resp[RESP_VIEW]++;
	ft_strdel(&str);
	return (OK);
}

