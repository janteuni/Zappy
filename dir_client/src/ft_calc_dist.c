/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:29:25 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/12 19:35:30 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

/*
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


int					ft_calc_dist(t_env *env, int stop)
{
	int				i;
	int				j;
	int				row_len;
	int				row_start;
	int				row_mid;
	int				dist;

	i = 0;
	j = 0;
	dist = 0;
	while (i <= env->level)
	{
		row_start = j;
		row_len = (i * 2) + 1;
		row_mid = row_start + (row_len / 2);
		while (j < row_start + row_len)
		{
			if (j < row_mid)
				dist = i + 1 + (row_mid - j);
			else if (j > row_mid)
				dist = i + 1 + ( j - row_mid);
			else
				dist = i;
			if (j == stop)
				break;
			j++;
		}
		i++;
	}
	return (dist);
}
