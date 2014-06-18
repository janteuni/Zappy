/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:37:54 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/18 18:08:32 by fbeck            ###   ########.fr       */
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
# define ABS(a,b)	((a - b > 0) ? a - b : b - a)
# define BUF_SIZE	50
# define INV_BUF	1024
# define BIG_BUF	4095

# define NB_STONES	6
# define INV_SIZE	7
# define SEE_SIZE	9
# define FOOD		0
# define LINEMATE	1
# define DERAUMERE	2
# define SIBUR		3
# define MENDIANE	4
# define PHIRAS		5
# define THYSTAME	6
# define PLAYERS	7
# define DIST		8

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

# define NO_RESP	(-1)
# define RESP_OK	0
# define RESP_VIEW	1
# define RESP_INV	2
# define RESP_VAL	3
# define NB_RESP	4

# define FORW		"avance\n"
# define RIGHT		"droite\n"
# define LEFT		"gauche\n"
# define INV		"inventaire\n"
# define VIEW		"voir\n"
# define CMD(X)		((t_cmd *)X->content)

# define DEAD		"mort"
# define MOVE		"deplacement"
# define MSG		"message"
# define ELEV		"elevation en cours"
# define ELEV_END	"niveau actuel"
# define KO			"ko"
# define LIST		"{"

typedef struct		s_cmd
{
	char			*cmd;
	char			*opt;
	int				resp;
}					t_cmd;

typedef struct		s_env
{
	char			*team;
	char			*addr;
	int				port;
	int				socket;
	char			**cmds;
	int				*resp;
	int				**incantation;
	int				dead;
	int				level;
	int				connect_nb;
	int				x;
	int				y;
	int				inv[INV_SIZE];
	int				**view;
	t_list			*moves;
	int				elevating;
	int				forked;
	int				laying;
	int				moved;
	int				dir_msg;
	int				pid;
	char			**envp;
	char			*path;
	int				dir_chg;
}					t_env;

t_env				*get_env(void);
int					create_client(t_env *env);
int					ft_confirm_connection(t_env *env);
void				ft_init_incantation(t_env *env);

/*
**			error.c
*/
int					error(char *err);

/*
**			ft_free.c
*/
void				ft_free_env(t_env **env);
void				ft_free_and_quit(t_env *env);


/*
**			ft_signal.c
*/
int					ft_setup_signal(void);

/*
**			ft_parse.c
*/
int					ft_parse(int ac, char **av, t_env *env);

/*
**			ft_loop.c
*/
int					ft_loop(t_env *env);
int					ft_expecting_resp(t_env *env);
int					ft_takemove(t_env *env);
void				ft_del_cmd_lst(void *content, size_t content_size);

/*
**			ft_get_inventory.c
*/
int					ft_get_inventory(t_env *env);
void				ft_read_inventory(t_env *env, char **s, int i);
void				ft_print_inv(t_env *env); //TAKE OUT!!!

/*
**			ft_look.c
*/
int					ft_look(t_env *env);
int					ft_read_view(t_env *env, char **split);

/*
**			ft_recv.c
*/
int					ft_recv(t_env *env);

/*
**			ft_send_cmd.c
*/
int					ft_send_cmd(t_env *env, char *cmd, int i);

/*
**			ft_elevation.c
*/
int					ft_enough_food(t_env *env);
int					ft_begin_elev(t_env *env, char *buf);
int					ft_end_elev(t_env *env, char *buf);
int					ft_elev_failed(t_env *env);

/*
**			ft_move.c
*/
int					ft_move(t_env *env, char *buf);

/*
**			ft_dead.c
*/
int					ft_dead(t_env *env, char *buf);

/*
**			ft_message.c
*/
int					ft_message(t_env *env, char *buf);

/*
**			ft_ia.c
*/
/*int					ft_set_cmd(t_cmd *cmd, int cmd_num, int resp, t_env *env);
int					ft_set_cmd_opt(t_cmd *cmd, int cmd_num, char *opt,
		t_env *env);*/
int					ft_ia(t_env *env);
int					ft_find(t_env *env, int obj);
/*int					ft_find_food(t_env *env);*/
int					ft_push_cmd(t_env *env, int cmd_num, char *opt, int resp);

/*
**			ft_calc_dist.c
*/
int					ft_calc_dist(int squ);
int					ft_calc_level(int squ);

/*
**			ft_get_route.c
*/
int					ft_get_route(t_env *env, int squ);
int					ft_avance(t_env *env, int num);

/*
**			ft_fork.c
*/
int					ft_fork(t_env *env);
int					ft_connect_egg(t_env *env);
int					ft_reset_env(t_env *env);

/*
**			ft_check.c
*/
int					ft_check_inv_stones(t_env *env);
int					ft_check_squ_stones(t_env *env);

/*
**			ft_incantation.c
*/
char				*ft_get_str(int obj);
int					ft_putdown(t_env *env, int stone);
int					ft_putdown_stones(t_env *env);
int					ft_get_people_here(t_env *env);

/*
**			ft_find_stones.c
*/
int					ft_find_stones(t_env *env);

/*
**			ft_follow_msg.c
*/
int					ft_follow_msg(t_env *env);
void				ft_dir_left(t_env *env, int dir);
void				ft_dir_right(t_env *env, int dir);
#endif
