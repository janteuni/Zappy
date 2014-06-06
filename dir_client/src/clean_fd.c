/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i.yanteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:23:45 by i.yanteuni          #+#    #+#             */
/*   Updated: 2014/06/06 19:42:56 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

void	clean_fd(t_env *env)
{
	env->fd_socket.buf_offset = 0;
	env->fd_socket.fct_read = NULL;
	env->fd_socket.fct_write = NULL;
	if (env->fd_socket.line)
		ft_lstdel(&env->fd_socket.line, ft_del);
	if (env->fd_socket.line_read)
		ft_lstdel(&env->fd_socket.line_read, ft_del);
}
