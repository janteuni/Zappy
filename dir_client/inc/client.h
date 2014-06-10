/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:37:54 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/10 11:49:14 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include <stdio.h>
# include "libft.h"
# include "zappy.h"

# define OK			0
# define ERR		-1

# define MAX(a,b)	((a > b) ? a : b)
# define BUF_SIZE	50
# define INV_BUF	1024
# define BIG_BUF	4095

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

# define NB_CMDS	12
# define AVANCE		0
# define DROITE		1
# define GAUCHE		2
# define VOIR		3
# define INVENT		4
# define PREND		5
# define POSE		6
# define EXPUL		7
# define BROAD		8
# define INCANT		9
# define FORK		10
# define CON_NB		11
# define SUCCESS	0
# define FAIL		1

# define DEAD		"mort"
# define MOVE		"deplacement"
# define MSG		"message"
# define ELEV		"elevation en cours"
# define ELEV_END	"niveau actuel"
# define OK			"ok"
# define KO			"ko"
# define LIST		"{"



typedef struct		s_env
{
	char			*team;
	char			*addr;
	int				port;
	int				socket;
	int				*cmds;
	char			**replies;
	fd_set			readfd;
	int				dead;
	int				level;
	int				client_nb;
	int				x;
	int				y;
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

/*
**			ft_set_replies.c
*/
int					ft_set_replies(t_env *env, char *succ, char *fail);

#endif
