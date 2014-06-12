/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:29:25 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/12 18:47:48 by fbeck            ###   ########.fr       */
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


int					ft_calc_dist(t_env *env...)
{
	int				i;
	int				j;
	int				row_len;

	i = 0;
	j = 0;
	while (i <= env->level)
	{
		row_len = (i * 2) + 1;



		ft_compute_row(env, i, );
		i++;
	}

	return (OK);
}
