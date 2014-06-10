/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_replies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 11:41:57 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/10 15:34:55 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

int					ft_set_replies(t_env *env, char *succ, char *fail)
{
	if (env->replies[SUCCESS])
		free(env->replies[SUCCESS]);
	env->replies[SUCCESS] = ft_strdup(succ);
	if (env->replies[FAIL])
		free(env->replies[FAIL]);
	env->replies[FAIL] = ft_strdup(fail);
	return (OK);
}

