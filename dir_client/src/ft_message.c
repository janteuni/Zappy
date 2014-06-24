/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 16:44:15 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 21:24:55 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int			ft_same_level(t_env *env, char *str)
{
	char			*ptr;
	int				level;

	level = -1;
	ptr = ft_strchr(str, ' ');
	if (ptr && ptr[0] && ptr[1])
	{
		level = (int)ptr[1] - '0';
	}
	if (level == env->level)
	{
		return (YES);
	}
	return (NO);
}

static int			ft_get_dir(char *buf)
{
	char			*ptr;
	int				dir;

	ptr = ft_strchr(buf, ' ');
	if (ptr && ptr[0] && ptr[1])
	{
		dir = (int)ptr[1] - '0';
		return (dir);
	}
	return (ERR);
}

static char			*ft_get_msg(char *buf)
{
	char			*ptr;
	char			*str;

	ptr = ft_strchr(buf, ',');
	if (ptr && ptr[0] && ptr[1])
	{
		str = &ptr[1];
		return (str);
	}
	return (NULL);
}

int					ft_message(t_env *env, char *buf)
{
	char			*str;
	int				dir;

	str = NULL;
	if ((dir = ft_get_dir(buf)) < 0)
		return (ERR);
	if (!(str = ft_get_msg(buf)))
		return (ERR);
	if (!ft_strncmp(str, env->team, ft_strlen(env->team)))
	{
		if (ft_same_level(env, str))
			env->dir_msg = dir;
	}
	else
	{
		if (dir == 0)
			env->expul = 1;
	}
	return (OK);
}
