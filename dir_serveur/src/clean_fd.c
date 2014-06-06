/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:23:45 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/06 11:15:28 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

void	clean_fd(t_fd *fd)
{
	t_env		*env;

	env = get_env();
	fd->type = FREE;
	fd->my_cs = 0;
	fd->buf_offset = 0;
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	if (fd->line)
		ft_lstdel(&fd->line, ft_del);
	if (fd->line_read)
		ft_lstdel(&fd->line_read, ft_del);
}
