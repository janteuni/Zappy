/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 14:27:08 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 15:24:16 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

void				ft_messages_select(t_env *env)
{
	struct timeval	tv;
	t_list			*message;
	long int		now;

	gettimeofday(&tv, NULL);
	now = 1000000 * tv.tv_sec + tv.tv_usec;
	message = env->messages;
	while (message != NULL)
	{
		if (((t_message *)message->content)->timestamp <= now)
			ft_messages_del(env, message);
		message = message->next;
	}
}

void				ft_messages_del(t_env *env, t_list *to_del)
{
	int				cs;
	char			*msg;

	cs = ((t_message *)to_del->content)->cs;
	msg = ((t_message *)to_del->content)->msg;
	ft_reply_in_buff(env, cs, msg);
	ft_del_elem(&env->messages, to_del, ft_del_mess);
}
