/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:21:03 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/10 15:39:19 by janteuni         ###   ########.fr       */
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

typedef struct		s_cmd
{
	char			*name;
	void			(*fn)();
}					t_cmd;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				o;
}					t_pos;

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
	int				inventory[NB_STUFF];
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
	t_team			*teams;
	int				max_team;
	t_fd			*fd_socket;
	fd_set			fd_read;
	fd_set			fd_write;
	int				***map;
	char			stuff[NB_STUFF][12];
	int				**incantation;
	t_list			*messages;
}					t_env;

t_env				*get_env(void);
int					parser(t_env *env, int argc, char **argv);
int					error(char *err);

int					create_server(t_env *env);
void				ft_loop(t_env *env);
void				clean_fd(t_fd *fd);
void				server_accept(t_env *env);
void				client_read(t_env *env, int cs);
void				client_write(t_env *env, int cs);
void				do_select(t_env *env);
void				check_fd(t_env *env);
void				init_fd(t_env *env);

int					ft_receive(t_env *env, int cs);
void				ft_stock_line(int cs, char *buffer);
void				ft_treat_msg(t_env *env, int cs, char *msg);
void				ft_reply_in_buff(t_env *env, int cs, char *msg);
void				ft_treat_cmd(char *rcv, t_env *env, int cs);

void				ft_null(void *d, size_t s);
void				del_list(t_list **begin, t_list *to_del);
void				ft_del(void *d, size_t s);
void				ft_del_mess(void *d, size_t s);
void				ft_del_elem(t_list **begin, t_list *to_del, void (*del)(void *, size_t));
int					ft_exit(char *err);

int					ft_pars_flag(int *i, char **argv, int argc, t_env *env);
void				ft_print_map(t_env *env, int k);
int					ft_init_map(t_env *env);

int					ft_add_me_team(t_env *env, int cs, char *rcv);
int					ft_place_me(t_env *env, int cs);
void				ft_init_incantation(t_env *env);
void				ft_check_incantation(t_env *env, int cs);

void				ft_treat_eat(t_env *env);
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

void				ft_messages_select(t_env *env);
void				ft_messages_add(t_env *env, int cs, char *msg, int t);
void				ft_messages_del(t_env *env, t_list *to_del);

void				ft_graphic_function(t_env *env, int cs, char *rcv);
void				ft_graphic_init(t_env *env, int cs);

#endif
