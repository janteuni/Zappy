/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 10:18:30 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/06 11:19:08 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_stock_line(int cs, char *buffer)
{
	t_env		*env;
	char		ret[BUF_SIZE + 2];

	ft_bzero(ret, BUF_SIZE + 1);
	env = get_env();
	ft_strncpy(ret, buffer, BUF_SIZE);
	ft_lstpush(&env->fd_socket[cs].line_read, ft_lstnew(ret, BUF_SIZE + 2));
}
