/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:53:01 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 20:21:49 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

int					error(char *err)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(err, 2);
	return (ERR);
}

void				ft_free_and_quit(t_env *env)
{
	ft_free_tab((void ***)&env->cmds);
	ft_memdel((void **)&env->resp);
	if (env->view)
		ft_free_tab((void ***)&env->view);
	ft_lstdel(&env->moves, ft_del_cmd_lst);
	exit(0);
}
