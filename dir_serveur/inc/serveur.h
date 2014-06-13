/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:21:03 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 17:36:40 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <sys/select.h>
# include <stdio.h>
# include "libft.h"

# define OK			0
# define ERR		-1

# define YES		1
# define NO			0

# define SERVER		0
# define CLIENT		1
# define FREE		2
# define GRAPHIC	3

# define BUF_SIZE	4096
# define BUF_NAME	10
# define MAX(a,b)	((a > b) ? a : b)
# define MSG_NULL	-1
# define NB_CMDS	12
# define NB_STUFF	7
# define NB_LEVEL	9

# define WIDTH		env->width
# define HEIGHT		env->height
# define POSX(CS)	env->fd_socket[CS].pos.x
# define POSY(CS)	env->fd_socket[CS].pos.y
# define OR(CS)		env->fd_socket[CS].pos.o
# define LEVEL(CS)	env->fd_socket[CS].level
# define TOTEM		env->incantation
# define TOTX(CS)	env->fd_socket[CS].incant.x
# define TOTY(CS)	env->fd_socket[CS].incant.y
# define INV(CS)	env->fd_socket[CS].inventory
# define SNAP		env->fd_socket[i].snapshot

# define N			1
# define E			2
# define S			3
# define O			4

# define FOOD		0
# define PLAYERS	0
# define LINEMATE	1
# define DERAUMERE	2
# define SIBUR		3
# define MENDIANE	4
# define PHIRAS		5
# define THYSTAME	6
# define INCANT		7

# define GESTATION	0
# define DEATH		-1
# define BORN		1

typedef struct		s_action
{
	char			*rcv;
	int				cs;
	long int		timestamp;
	void			(*fn)();
}					t_action;

typedef struct		s_cmd
{
	char			*name;
	int				t;
	void			(*fn)();
}					t_cmd;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				o;
}					t_pos;

typedef struct		s_snapshot
{
	int				master;
	t_list			*players;
	int				stuff[NB_STUFF];
}					t_snapshot;

typedef struct		s_egg
{
	int				father;
	int				life;
	int				num;
	char			*team;
	int				state;
	t_pos			pos;
}					t_egg;

typedef struct		s_fd
{
	int				level;
	int				my_cs;
	int				type;
	void			(*fct_read)();
	void			(*fct_write)();
	char			buf_read[BUF_SIZE + 1];
	char			buf_write[BUF_SIZE + 1];
	int				buf_offset;
	t_list			*line;
	t_list			*line_read;
	char			*my_team;
	t_pos			pos;
	t_pos			incant;
	long int		last_cmd;
	int				inventory[NB_STUFF];
	t_snapshot		snapshot;
}					t_fd;

typedef struct		s_message
{
	char			*msg;
	int				cs;
	long int		timestamp;
}					t_message;

typedef struct		s_player
{
	int				sock;
}					t_player;

typedef struct		s_team
{
	char			*name;
	int				nb_player;
	int				max_player;
	t_list			*players;
}					t_team;

typedef struct		s_env
{
	int				width;
	int				height;
	int				time;
	int				nb_player;
	int				port;
	int				sock_server;
	int				max_fd;
	int				max;
	int				r;
	int				graphic;
	t_team			*teams;
	int				max_team;
	t_fd			*fd_socket;
	fd_set			fd_read;
	fd_set			fd_write;
	int				***map;
	char			stuff[NB_STUFF][12];
	int				**incantation;
	t_list			*actions;
	t_list			*eggs;
	int				count_egg;
}					t_env;

/*
** SERVER
*/
int					create_server(t_env *env);
void				ft_loop(t_env *env);
void				clean_fd(t_fd *fd);
void				server_accept(t_env *env);
void				client_read(t_env *env, int cs);
void				client_write(t_env *env, int cs);
void				do_select(t_env *env);
void				check_fd(t_env *env);
void				init_fd(t_env *env);

/*
** CMD BUFFER
*/
int					ft_receive(t_env *env, int cs);
void				ft_stock_line(int cs, char *buffer);
void				ft_treat_msg(t_env *env, int cs, char *msg);
void				ft_reply_in_buff(t_env *env, int cs, char *msg);
void				ft_treat_cmd(char *rcv, t_env *env, int cs);

/*
**	TOOLS DELETE AND EXIT
*/
int					error(char *err);
void				ft_null(void *d, size_t s);
void				del_list(t_list **begin, t_list *to_del);
void				ft_del(void *d, size_t s);
void				ft_del_mess(void *d, size_t s);
void				ft_del_elem(t_list **begin, t_list *to_del,
		void (*del)(void *, size_t));
void				ft_del_action(void *d, size_t s);
int					ft_exit(char *err);
void				ft_del_egg(void *d, size_t s);

/*
** INIT
*/
t_env				*get_env(void);
int					parser(t_env *env, int argc, char **argv);
int					ft_pars_flag(int *i, char **argv, int argc, t_env *env);
void				ft_print_map(t_env *env, int k);
void				ft_init_map(t_env *env);

void				ft_max_players_in_team(t_env *env);
int					ft_add_me_team(t_env *env, int cs, char *rcv);
int					ft_place_me(t_env *env, int cs);
void				ft_init_incantation(t_env *env);

/*
** CLIENT CMDS
*/
void				ft_check_incantation(t_env *env, int cs, char *rcv);
void				ft_treat_eat(t_env *env);
void				ft_treat_egg(t_env *env, int cs, char *rcv);
void				ft_treat_expulse(t_env *env, int cs, char *rcv);
void				ft_treat_connect_nbr(t_env *env, int cs, char *rcv);
void				ft_treat_fork(t_env *env, int cs, char *rcv);
void				ft_treat_incantation(t_env *env, int cs, char *rcv);
void				ft_treat_broadcast(t_env *env, int cs, char *rcv);
void				ft_treat_inventory(t_env *env, int cs, char *rcv);
void				ft_treat_put(t_env *env, int cs, char *rcv);
void				ft_treat_get(t_env *env, int cs, char *rcv);
void				ft_treat_vision(t_env *env, int cs, char *rcv);
void				ft_treat_avance(t_env *env, int cs, char *rcv);
void				ft_treat_left(t_env *env, int cs, char *rcv);
void				ft_treat_right(t_env *env, int cs, char *rcv);
int					ft_function_cmd(t_env *env, int cs, char *rcv);
void				ft_snapshot(t_env *env, int cs, int stuff[NB_STUFF]);
t_list				*ft_get_players(t_env *env, int cs);
t_list				*ft_get_players_same_level(t_env *env, int cs);

/*
** ACTION LIST
*/
void				ft_action_add(int cs, int t, void (*fn)(), char *rcv);
void				ft_action_del(t_env *env, t_list *to_del);
void				ft_actions_select(t_env *env);
void				ft_action_tm(int cs, int t, void (*fn)(), char *rcv);

/*
** CLIENT GRAPHIC
*/
void				ft_graphic_function(t_env *env, int cs, char *rcv);
void				ft_graphic_init(t_env *env, int cs);
char				*ft_graphic_bct(t_env *env, int x, int y);
void				ft_graphic_all_map(t_env *env, int cs);
char				*ft_graphic_tna(t_env *env);
char				*ft_graphic_pnw(t_env *env, int cs);
char				*ft_graphic_ppo(t_env *env, int cs);
void				ft_graphic_reply(t_env *env, int cs, char *(*fn)());
char				*ft_graphic_plv(t_env *env, int cs);
char				*ft_graphic_pin(t_env *env, int cs);
char				*ft_graphic_pex(t_env *env, int cs);
char				*ft_graphic_pbc(t_env *env, int cs, char *msg);
char				*ft_graphic_pic(t_env *env, int cs);
void				ft_graphic_pie(t_env *env, int cs, int result);
void				ft_graphic_pdr(t_env *env, int cs, int i);
void				ft_graphic_pgt(t_env *env, int cs, int i);
char				*ft_graphic_pfk(t_env *env, int cs);
char				*ft_graphic_pdi(t_env *env, int cs);
char				*ft_graphic_enw(t_env *env, int cs, int egg);
char				*ft_graphic_eht(t_env *env, int cs);
char				*ft_graphic_ebo(t_env *env, int cs);
char				*ft_graphic_edi(t_env *env, int cs);

/*
** Miscelleanous
*/
int					ft_lst_contains(t_list *tocheck, t_list *container);
int					ft_compare_stuff(t_env *env, int tab[NB_STUFF], int level);
int					ft_calcul_nb(t_env *env, int cs);

#endif
