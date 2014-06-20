/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:41:18 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/20 15:05:12 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	AC	   1    2    3    4    5      6     7
Usage: ./client -n <team> -p <port> [-h <hostname>]
	AV     0    1    2    3    4      5     6

-n nom d'equipe
-p port
-h nom de la machine par defaut c'est le localhost
*/
#include "libft.h"
#include "client.h"

void				ft_usage(char *str)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" -n <team name> -p <port> [-h <hostname>]", 2);
}

int					ft_read_params(int ac, int i, char **av, t_env *env)
{
	if (!ft_strcmp(av[i], "-n") && !env->team)
	{
		if ( i + 1 == ac)
			return (error("Please enter a valid team name"));
		else
			env->team = av[i + 1];
	}
	else if (!ft_strcmp(av[i], "-p") && !env->port)
	{
		if ( i + 1 == ac || (env->port = ft_atoi(av[i + 1])) < 1)
			return (error("Please enter a valid port"));
	}
	else if (!ft_strcmp(av[i], "-h") && !env->addr)
	{
		if ( i + 1 < ac )
			env->addr = av[i + 1];
	}
	else
	{
		ft_usage(av[0]);
		return (-1);
	}
	return (0);
}

int					ft_parse(int ac, char **av, t_env *env)
{
	int				i;

	if (ac < 5)
	{
		ft_usage(av[0]);
		return (-1);
	}
	i = 1;
	while (i < ac)
	{
		if (ft_read_params(ac, i, av , env) < 0)
			return (ERR);
		i +=2;
	}
	env->addr = (!env->addr ? ft_strdup("localhost") : env->addr);
	dprintf(env->aff, "TEAM = [%s]\nPORT = [%d]\nADDR = [%s] \n",env->team, env->port, env->addr );
	return (0);
}
