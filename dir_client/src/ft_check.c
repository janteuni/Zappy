/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:45:13 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 19:59:01 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int					ft_check_squ_stones(t_env *env)
{
	if (env->incantation[env->level + 1][LINEMATE] > env->view[0][LINEMATE])
		return (NO);
	if (env->incantation[env->level + 1][DERAUMERE] > env->view[0][DERAUMERE])
		return (NO);
	if (env->incantation[env->level + 1][SIBUR] > env->view[0][SIBUR])
		return (NO);
	if (env->incantation[env->level + 1][MENDIANE] > env->view[0][MENDIANE])
		return (NO);
	if (env->incantation[env->level + 1][PHIRAS] > env->view[0][PHIRAS])
		return (NO);
	if (env->incantation[env->level + 1][THYSTAME] > env->view[0][THYSTAME])
		return (NO);
	return (YES);
}

int					ft_check_inv_stones(t_env *env)
{
	if (env->incantation[env->level + 1][LINEMATE] > env->inv[LINEMATE])
		return (NO);
	if (env->incantation[env->level + 1][DERAUMERE] > env->inv[DERAUMERE])
		return (NO);
	if (env->incantation[env->level + 1][SIBUR] > env->inv[SIBUR])
		return (NO);
	if (env->incantation[env->level + 1][MENDIANE] > env->inv[MENDIANE])
		return (NO);
	if (env->incantation[env->level + 1][PHIRAS] > env->inv[PHIRAS])
		return (NO);
	if (env->incantation[env->level + 1][THYSTAME] > env->inv[THYSTAME])
		return (NO);
	return (YES);
}
