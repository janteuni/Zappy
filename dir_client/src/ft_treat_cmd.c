/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 14:26:27 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/06 11:22:13 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_cmd(char *rcv, t_env *env, int cs)
{
	(void)env;
	(void)cs;
	printf("%s\n", rcv);
}
