/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 15:36:37 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/10 16:59:48 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_msz(t_env *env)
{
	char			*ret;
	char			*itoa;
	char			*tmp;

	itoa = ft_itoa(env->width);
	ret = ft_strjoin("msz ", itoa);
	ft_memdel((void **)&itoa);
	itoa = ft_itoa(env->height);
	tmp = ft_strjoin(ret, " ");
	ft_memdel((void **)&ret);
	ret = ft_strjoin(tmp, itoa);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&tmp);
	tmp = ft_strjoin(ret, "\n");
	ft_memdel((void **)&ret);
	return (tmp);
}

char				*ft_graphic_sgt(t_env *env)
{
	char			*ret;
	char			*tmp;
	char			*itoa;

	itoa = ft_itoa(env->time);
	tmp = ft_strjoin("sgt ", itoa);
	ft_memdel((void **)&itoa);
	ret = ft_strjoin(tmp, "\n");
	ft_memdel((void **)&tmp);
	return (ret);
}

void				ft_graphic_init(t_env *env, int cs)
{
	char			*push;

	env->fd_socket[cs].type = GRAPHIC;
	printf("graphic init\n");
	push = ft_graphic_msz(env);
	ft_lstadd(&env->fd_socket[cs].line, ft_lstnew(push, ft_strlen(push)));
	ft_memdel((void **)&push);
	push = ft_graphic_sgt(env);
	ft_reply_in_buff(env, cs, push);
	ft_memdel((void **)&push);
}
