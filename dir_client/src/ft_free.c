/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 17:43:30 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/17 19:25:56 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

void				ft_free_env(t_env **env)
{
	t_env			*ptr;

	ptr = *env;
	ft_free_tab((void ***)&ptr->cmds);/* free tbl of cmds (char **) */
	ft_memdel((void **)&ptr->resp);/* free tbl of responses (int *) */
	if (ptr->view)
		ft_free_tab((void ***)&ptr->view); /* free view tbl (int **) */
	ft_free_tab((void ***)&ptr->incantation); /* free incantation tbl (int **) */
	ft_lstdel(&ptr->moves, ft_del_cmd_lst); /* free list of moves */
	free(*env); /* free env itself */
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
