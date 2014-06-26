/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:29:25 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 19:59:08 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "client.h"

int					ft_calc_dist(int squ)
{
	int				level_nb;
	int				row_len;
	int				row_start;
	int				row_mid;
	int				dist;

	level_nb = (int)sqrt(squ);
	dist = 0;
	row_start = level_nb * level_nb;
	row_len = (level_nb * 2) + 1;
	row_mid = row_start + (row_len / 2);
	if (squ < row_mid)
		dist = level_nb + 1 + (row_mid - squ);
	else if (squ > row_mid)
		dist = level_nb + 1 + (squ - row_mid);
	else
		dist = level_nb;
	return (dist);
}
