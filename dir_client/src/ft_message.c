/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 16:44:15 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/19 20:19:13 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

/*int					ft_read_message(t_env *env, char *msg)
{
	(void)env;
	(void)msg;
	return (OK);
}*/

int					ft_same_level(t_env *env, char *str)
{
	char			*ptr;
	int				level;

	level = -1;
	ptr = ft_strchr(str, ' ');
	if (ptr && ptr[0] && ptr[1])
	{
		level = (int)ptr[1] - '0';
	}
	printf("[%d]\tlevel in msg [%d] my level [%d]\n",env->pid,level, env->level );
	if (level == env->level)
	{
		return (YES);
	}
	return (NO);
}

int					ft_message(t_env *env, char *buf)
{
	char			*ptr;
	char			*str;
	int				dir;

	str = NULL;
	ptr = ft_strchr(buf, ' ');
	if (ptr && ptr[0] && ptr[1])
		dir = (int)ptr[1] - '0';
	else
	{
		printf("[%d]\tReceived a response I don't understand '%s'\n",env->pid, buf);
		return (ERR);
	}
	ptr = ft_strchr(buf, ',');
	if (ptr && ptr[0] && ptr[1])
		str = &ptr[1];
	else
	{
		printf("[%d]\tReceived a response I don't understand '%s'\n",env->pid, buf);
		return (ERR);
	}
	if (!ft_strncmp(str, env->team, ft_strlen(env->team)))
	{
		printf("[%d]\tRECEIVED MSG FROM MY TEAM\n",env->pid);
		if (ft_same_level(env, str))
		{
			printf("[%d]\tITS MY LEVEL - I'm GOING!\n",env->pid);
			env->dir_msg = dir;
		}
		else
			printf("[%d]\tNOT MY LEVEL (%d) - CANT HELP\n",env->pid, env->level);
	}
	else
		printf("[%d]\tNOT MY TEAM (%s) - [%s]\n",env->pid, env->team, str );
	return (OK);
}
