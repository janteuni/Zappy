/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:39:44 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/11 12:51:09 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int					ft_expecting_resp(t_env *env)
{
	int				i;

	i = 0;
	while (i < NB_RESP)
	{
		if (env->resp[i] > 0)
			return (YES);
		++i;
	}
	return (NO);
}

int					ft_print_responsetab(t_env *env)
{
	int				i;
	char			*str;

	i = 0;
	while (i < NB_RESP)
	{
		if (i == 0)
			str = "OK / KO";
		else if (i == 1)
			str = "VIEW";
		else if (i == 2)
			str = "INVENTORY";
		else
			str = "VALUE";
		printf("EXPECTING %d RESPONSE[%s]\n", env->resp[i], str );
		++i;
	}
	return (OK);
}

int					ft_takemove(t_env *env)
{
	ft_print_responsetab(env);
	if (env->elevating || ft_expecting_resp(env))
		return (OK);
	else
		ft_get_inventory(env);
		//IA HERE
		return (OK);
}

int					ft_loop(t_env *env)
{
	int				i;
	/*char			*str;*/

	i = 0;
	ft_forwards(env);
	ft_left(env);
	ft_right(env);
/*	env->resp[RESP_OK] += 2;
	if ((send(env->socket, "avance\n", ft_strlen("avance\n"), 0)) < 0)
		return (error("Failed to send command"));
	if ((send(env->socket, "gauche\n", ft_strlen("gauche\n"), 0)) < 0)
		return (error("Failed to send command"));*/
/*	ft_look(env);*/
	while (!env->dead)
	{
		ft_recv(env);
		ft_takemove(env);
		++i;
	}
	return (OK);
}
