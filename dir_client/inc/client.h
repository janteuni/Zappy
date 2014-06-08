/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:37:54 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/08 18:21:56 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include <stdio.h>
# include "libft.h"

# define OK			0
# define ERR		-1

# define MAX(a,b)	((a > b) ? a : b)
# define BUF_SIZE	50
# define INV_BUF	1024
# define LOOK_BUF	4096

# define INV_SIZE	7
# define SEE_SIZE	8
# define FOOD		0
# define LINEMATE	1
# define DERAUMERE	2
# define SIBUR		3
# define MENDIANE	4
# define PHIRAS		5
# define THYSTAME	6
# define PLAYERS	7

typedef struct		s_info
{
	int				client_nb;
	int				x;
	int				y;

}					t_info;

typedef struct		s_env
{
	char			*team;
	char			*addr;
	int				port;
	int				socket;
	t_info			myinfo;
	int				dead;
	int				level;
	int				inv[INV_SIZE];
}					t_env;

t_env				*get_env(void);
int					error(char *err);
int					create_client(t_env *env);

/*
**			ft_parse.c
*/
int					ft_parse(int ac, char **av, t_env *env);

/*
**			ft_loop.c
*/
int					ft_loop(t_env *env);
int					ft_get_inventory(t_env *env);

/*
**			ft_get_inventory.c
*/
int					ft_get_inventory(t_env *env);

/*
**			ft_look.c
*/
int					ft_look(t_env *env);

#endif
