/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:51:20 by janteuni          #+#    #+#             */
/*   Updated: 2014/05/20 10:24:31 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int					parser(t_env *env, int argc, char **argv)
{
	if (argc != 2)
		return (error("Usage: ./serveur <port>"));
	env->port = ft_atoi(argv[1]);
	return (OK);
}
