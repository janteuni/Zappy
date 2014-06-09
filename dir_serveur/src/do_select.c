/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:21:50 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 14:47:05 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include <time.h>

void	do_select(t_env *env)
{
	struct timeval	tv;

	tv.tv_sec = 0;
	tv.tv_usec = 50000;
	env->r = select(env->max + 1, &env->fd_read, &env->fd_write, NULL, &tv);
}
