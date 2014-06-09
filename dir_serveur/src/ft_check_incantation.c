/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_incantation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 10:49:51 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 18:24:06 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int					st_incantation_succeed(t_env *env, int cs)
{
	if (env->map[TOTY(cs)][TOTX(cs)][INCANT] == NO)
		return (ERR);
	if (POSX(cs) == TOTX(cs) && POSY(cs) == TOTY(cs))
		return (OK);
	env->map[TOTY(cs)][TOTX(cs)][INCANT] = NO;
	return (ERR);
}

void						ft_check_incantation(t_env *env, int cs)
{
	char			*itoa;
	char			*join;

	if (st_incantation_succeed(env, cs) == OK)
		env->fd_socket[cs].level += 1;
	itoa =  ft_itoa(env->fd_socket[cs].level);
	join = ft_strjoin("niveau ", itoa);
	TOTY(cs) = -1;
	TOTX(cs) = -1;
	ft_reply_in_buff(env, cs, join);
	ft_memdel((void **)&itoa);
	ft_memdel((void **)&join);
}
