/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 16:44:15 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/19 15:50:21 by fbeck            ###   ########.fr       */
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

	printf("GET LEVEL IN MSG [%s]\n",str );
	level = -1;
	ptr = ft_strchr(str, ' ');
	if (ptr && ptr[0] && ptr[1])
	{
		printf("ptr points to a [%c], ptr[1] is a [%c]\n",*ptr, ptr[1] );
		level = (int)ptr[1] - '0';
	}
	printf("level in msg [%d] my level [%d]\n",level, env->level );
	if (level == env->level)
	{
		printf("return YES THE SAME LEVEL\n");
		return (YES);
	}
	printf("return NO DIFFERENT LEVEL\n");
	return (NO);
}

int					ft_message(t_env *env, char *buf)
{
	char			*ptr;
	char			*str;
	int				dir;

	printf("MSG RECEIVED - [%s]\n",buf );
	str = NULL;
	ptr = ft_strchr(buf, ' ');
	if (ptr && ptr[0] && ptr[1])
		dir = (int)ptr[1] - '0';
	else
	{
		printf("Received a response I don't understand '%s'\n", buf);
		return (ERR);
	}
	ptr = ft_strchr(buf, ',');
	if (ptr && ptr[0] && ptr[1])
		str = &ptr[1];
	else
	{
		printf("Received a response I don't understand '%s'\n", buf);
		return (ERR);
	}
	if (!ft_strncmp(str, env->team, ft_strlen(env->team)))
	{
		printf("RECEIVED MSG FROM MY TEAM\n");
		if (ft_same_level(env, str))
		{
			printf("ITS MY LEVEL - I'm GOING!\n");
			env->dir_msg = dir;
		}
		else
			printf("NOT MY LEVEL (%d) - CANT HELP\n", env->level);
	}
	else
		printf("NOT MY TEAM (%s) - [%s]\n", env->team, str );
	return (OK);
}
