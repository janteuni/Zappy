/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 14:18:44 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 15:24:18 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

void				ft_messages_add(t_env *env, int cs, char *msg, int t)
{
	t_message		new_message;
	long int		timestamp;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	timestamp = (1000000 * tv.tv_sec + tv.tv_usec) + ((t / env->time) * 1000000);
	new_message.msg = msg;
	new_message.cs = cs;
	new_message.timestamp = timestamp;
	ft_lstpush(&env->messages, ft_lstnew(&new_message, sizeof(new_message)));
}
