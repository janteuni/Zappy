/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 19:34:22 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/16 19:48:21 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "client.h"

static void			ft_quit(int i)
{
	t_env 			*env;

	env = get_env();
	(void)i;
	ft_free_and_quit(env);
}

int					ft_setup_signal(void)
{
	if ((signal(SIGQUIT, ft_quit) == SIG_ERR)
			|| (signal(SIGINT, ft_quit) == SIG_ERR))
		return (ERR);
	return (OK);
}
