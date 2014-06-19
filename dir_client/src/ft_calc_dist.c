/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:29:25 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/19 12:00:56 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "client.h"

/* YANNS SUPER FORMULA
    while (i <= player->level)
        {
            compute_rows(e, player, msg, i);
            i++;
        }
    init_pos(player, &x, &y, i);
    j = 0;
    while (j < ((i * 2) + 1))
    {
        correct_pos(e, &x, &y);
        check_tile(e, msg, x, y);
        if ((k = get_player_pos_voir(e->teams, x, y, player->id)) != 0)
            while (k-- > 0)
                ft_strcat(msg, " joueur");
        ft_strcat(msg, ",");
        inc_var(player, &x, &y);
        j++;
    }
*/
/*
int					ft_calc_level(int squ)
{
	int				l;

	l = 1;
	while (l * l <= squ)
		++l;
	return (l - 1);
}*/

int					ft_calc_dist(int squ)
{
	int				level_nb;
	int				row_len;
	int				row_start;
	int				row_mid;
	int				dist;

	/*level_nb = ft_calc_level(squ);*/
	level_nb = (int)sqrt(squ);
	dist = 0;
	row_start = level_nb * level_nb;
	row_len = (level_nb * 2) + 1;
	row_mid = row_start + (row_len / 2);
	if (squ < row_mid)
		dist = level_nb + 1 + (row_mid - squ);
	else if (squ > row_mid)
		dist = level_nb + 1 + ( squ - row_mid);
	else
		dist = level_nb;
	return (dist);
}

