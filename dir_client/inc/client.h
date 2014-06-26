/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:37:54 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/25 18:46:17 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdio.h>
# include "libft.h"
# include "zappy.h"

# define OK			0
# define ERR		-1

# define MAX(a,b)	((a > b) ? a : b)
# define ABS(a,b)	((a - b > 0) ? a - b : b - a)
# define BUF_SIZE	50
# define RECV_BUF	1000

# define NB_STONES	6
# define INV_SIZE	7
# define VIEW_SIZE	9
# define FOOD		0
# define LINEMATE	1
# define DERAUMERE	2
# define SIBUR		3
# define MENDIANE	4
# define PHIRAS		5
# define THYSTAME	6
# define PLAYERS	7
# define DIST		8
# define STONE_1	" linemate"
# define STONE_2	" deraumere"
# define STONE_3	" sibur"
# define STONE_4	" mendiane"
# define STONE_5	" phiras"
# define STONE_6	" thystame"

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

# define CMD(X)		((t_cmd *)X->content)

# define DEAD		"mort"
# define MSG		"message"

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
	int				view_size;
	t_list			*moves;
	int				elevating;
	int				moved;
	int				forked;
	int				laying;
	int				dir_msg;
	int				expul;
	char			**envp;
	char			*path;
	int				dir_chg;
	int				my_incant;
	t_list			*buffer;
}					t_env;

/*
**			STARTUP AND CREATE CONNECTION
*/
t_env				*get_env(void);
int					ft_parse(int ac, char **av, t_env *env);
int					create_client(t_env *env);
int					ft_confirm_connection(t_env *env);
int					ft_init_incantation(t_env *env);
int					ft_setup_signal(void);

/*
**			ERRORS AND FREE
*/
int					error(char *err);
void				ft_free_env(t_env **env);
void				ft_free_and_quit(t_env *env);

/*
**			THE LOOP
*/
void				ft_del_cmd_lst(void *content, size_t content_size);
int					ft_send_moves(t_env *env);
int					ft_loop(t_env *env);
int					ft_takemove(t_env *env);

/*
**			RECV THINGS
*/
int					ft_recv(t_env *env);
char				*ft_join_str(t_env *env, char *str);
void				ft_read_buffer(t_env *env, char *buf, int l, int start);
int					ft_read_line(t_env *env, char *line);
int					ft_read_list(t_env *env, char *buf);
int					ft_connect_nb(t_env *env, char *buf);
void				ft_read_inventory(t_env *env, char **s, int i);
int					ft_read_view(t_env *env, char **split);
int					ft_message(t_env *env, char *buf);
int					ft_move(t_env *env, char *buf);
int					ft_dead(t_env *env, char *buf);

/*
**			ELEVATION
*/
int					ft_enough_food(t_env *env);
int					ft_begin_elev(t_env *env, char *buf);
int					ft_end_elev(t_env *env, char *buf);
int					ft_elev_failed(t_env *env);

/*
**			ARTIFICIAL INTELLIGENCE
*/
int					ft_push_cmd(t_env *env, int cmd_num, char *opt, int resp);
int					ft_ia(t_env *env);
int					ft_find(t_env *env, int obj);
int					ft_random(t_env *env);
int					ft_calc_dist(int squ);
int					ft_calc_level(int squ);
int					ft_get_route(t_env *env, int squ);
int					ft_avance(t_env *env, int num);

/*
**			FORK
*/
int					ft_fork(t_env *env);

/*
**			INCANTATION
*/
char				*ft_get_str(int obj);
int					ft_putdown(t_env *env, int stone);
int					ft_putdown_stones(t_env *env);
int					ft_get_people_here(t_env *env);
int					ft_check_inv_stones(t_env *env);
int					ft_check_squ_stones(t_env *env);
void				ft_collect_stones(t_env *env);

/*
**			FOLLOW MESSAGE
*/
int					ft_follow_msg(t_env *env);
void				ft_dir_left(t_env *env, int dir);
void				ft_dir_right(t_env *env, int dir);

#endif
