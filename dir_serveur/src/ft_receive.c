/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 10:17:34 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/21 16:47:01 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>
#include "serveur.h"

char			*special_strchr(char *s1, char c, size_t n)
{
	char		*ptr;

	while (n > 0)
	{
		ptr = s1;
		if (*ptr == c)
			return (ptr);
		s1 = ptr + 1;
		n--;
	}
	return (NULL);
}

static void		st_loop(char *buffer, char *amsg, char **ptr, int *offset)
{
	int			i;

	i = 0;
	while (buffer + i != *ptr)
	{
		amsg[i] = buffer[i];
		(i)++;
	}
	amsg[i] = '\0';
	*ptr += 1;
	i = 0;
	while ((*ptr) + (i) < buffer + *offset)
	{
		buffer[i] = (*ptr)[i];
		(i)++;
	}
	*offset = (i);
}

void			control_receive(char *buffer, char *amsg, int *offset, int cs)
{
	char		*ptr;

	ptr = NULL;
	amsg[0] = MSG_NULL;
	if (*offset != 0)
	{
		if ((ptr = special_strchr(buffer, '\n', BUF_SIZE)))
			st_loop(buffer, amsg, &ptr, offset);
		else if ((ptr = special_strchr(buffer, '\0', BUF_SIZE)))
			*offset = ptr - buffer;
		else
		{
			ft_stock_line(cs, buffer);
			*offset = 0;
		}
		ft_memset(buffer + *offset, '\0', BUF_SIZE - *offset);
	}
}

int				ft_receive(t_env *env, int cs)
{
	int			i;
	char		msg[BUF_SIZE + 1];

	ft_bzero(msg, BUF_SIZE);
	control_receive(env->fd_socket[cs].buf_read, msg,
			&env->fd_socket[cs].buf_offset, cs);
	if (msg[0] != MSG_NULL)
	{
		i = 0;
		ft_treat_msg(env, cs, msg);
	}
	if (special_strchr(env->fd_socket[cs].buf_read, '\n', BUF_SIZE) != NULL)
		ft_receive(env, cs);
	return (OK);
}
