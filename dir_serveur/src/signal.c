/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 16:00:48 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 16:10:50 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include "serveur.h"

void				ft_ctr_c(int i)
{
	t_env		*env;

	(void)i;
	env = get_env();
	ft_treat_dead_all(env);
	if (env->graphic != -1)
		send(env->graphic, "seg CTR-C\n", 10, 0);
	exit (0);
}
