/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reoriente_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 17:33:29 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 17:38:25 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

t_pos		ft_reoriente_pos(t_pos pos_case, t_env *env, int cs)
{
	if (OR(cs) == N)
		pos_case.x = pos_case.x == WIDTH - 1 ? 0 : pos_case.x + 1;
	else if (OR(cs) == E)
		pos_case.y = pos_case.y == HEIGHT - 1 ? 0 : pos_case.y + 1;
	else if (OR(cs) == S)
		pos_case.x = pos_case.x == 0 ? WIDTH - 1 : pos_case.x - 1;
	else if (OR(cs) == O)
		pos_case.y = pos_case.y == 0 ? HEIGHT - 1 : pos_case.y - 1;
	return (pos_case);
}
