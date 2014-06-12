/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 16:44:15 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/11 18:08:50 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int					ft_read_message(t_env *env, char *msg)
{
	(void)env;
	(void)msg;
	return (OK);
}

int					ft_message(t_env *env, char *buf)
{
	char			*ptr;
	char			*str;
	int				dir;

	printf("MSG RECEIVED - [%s]\n",buf );
	str = NULL;
	ptr = ft_strchr(buf, ' ');
	if (ptr[0] && ptr[1])
		dir = (int)ptr[1] + '0';
	ptr = ft_strchr(buf, ',');
	if (ptr[0] && ptr[1])
		str = &ptr[1];
	if (!ft_strncmp(str, env->team, ft_strlen(env->team)))
	{
		ft_read_message(env, str);
		env->dir_msg = dir;
	}
	return (OK);
}
