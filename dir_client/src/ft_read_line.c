/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 21:34:36 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 21:39:13 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

int					ft_connect_nb(t_env *env, char *buf)
{
	int				new;

	new = ft_atoi(buf);
	if (!env->laying)
		env->connect_nb = new;
	else if (new > env->connect_nb)
	{
		env->connect_nb = new;
		ft_fork(env);
	}
	env->resp[RESP_VAL]--;
	return (OK);
}

int					ft_read_list(t_env *env, char *buf)
{
	char			*list;
	char			**split;
	char			*sp;

	(void)env;
	list = ft_strsub(buf, 1, ft_strlen(buf) - 2);
	split = ft_strsplit(list, ',');
	sp = ft_strchr(split[0], ' ');
	if (sp && sp[0] && sp[1] && ft_isdigit(sp[1]))
	{
		ft_read_inventory(env, split, 0);
		env->resp[RESP_INV]--;
	}
	else
	{
		ft_read_view(env, split);
		env->resp[RESP_VIEW]--;
	}
	free(list);
	ft_free_tab((void ***)&split);
	return (OK);
}

int					ft_read_line(t_env *env, char *line)
{
	if ((line[0] == 'o') || (line[0] == 'k'))
	{
		if (env->resp[RESP_OK] == 0 && env->elevating == 1)
			ft_elev_failed(env);
		else
			env->resp[RESP_OK]--;
		return (OK);
	}
	if (line[0] == '{')
		return (ft_read_list(env, line));
	if (line[0] == 'e')
		return (ft_begin_elev(env, line));
	if (line[0] == 'n')
		return (ft_end_elev(env, line));
	if (line[0] == 'd')
		return (ft_move(env, line));
	if (line[0] == 'm' && !ft_strncmp(DEAD, line, ft_strlen(DEAD)))
		return (ft_dead(env, line));
	if (line[0] == 'm' && !ft_strncmp(MSG, line, ft_strlen(MSG)))
		return (ft_message(env, line));
	if (ft_isdigit(line[0]))
		return (ft_connect_nb(env, line));
	return (OK);
}
