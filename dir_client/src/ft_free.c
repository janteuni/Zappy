/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 17:43:30 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 20:07:32 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

void				ft_free_env(t_env **env)
{
	t_env			*ptr;

	ptr = *env;
	ft_free_tab((void ***)&ptr->cmds);
	ft_memdel((void **)&ptr->resp);
	if (ptr->view)
		ft_free_tab((void ***)&ptr->view);
	ft_free_tab((void ***)&ptr->incantation);
	ft_lstdel(&ptr->moves, ft_del_cmd_lst);
	free(*env);
}

void				ft_free_and_quit(t_env *env)
{
	ft_free_tab((void ***)&env->cmds);
	ft_memdel((void **)&env->resp);
	if (env->view)
		ft_free_tab((void ***)&env->view);
	ft_free_tab((void ***)&env->incantation);
	ft_lstdel(&env->moves, ft_del_cmd_lst);
	exit(0);
}
