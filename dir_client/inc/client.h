/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:37:54 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/06 19:39:18 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include <stdio.h>
# include "libft.h"

# define OK			0
# define ERR		-1

# define SERVER		0
# define CLIENT		1
# define FREE		2

# define BUF_SIZE	50
# define BUF_NAME	10
# define MAX(a,b)	((a > b) ? a : b)
# define MSG_NULL	-1

typedef struct		s_fd
{
	void			(*fct_read)();
	void			(*fct_write)();
	char			buf_read[BUF_SIZE + 1];
	char			buf_write[BUF_SIZE + 1];
	int				buf_offset;
	t_list			*line;
	t_list			*line_read;
}					t_fd;

typedef struct		s_env
{
	char			*team;
	char			*host;
	int				port;
	int				socket;
	/*int				max_fd;*/
	int				max; /* 1 / 0*/
	int				r;/* select*/
	t_fd			fd_socket;
	fd_set			fd_read;
	fd_set			fd_write;
}					t_env;

t_env				*get_env(void);
int					parser(t_env *env, int argc, char **argv);
int					error(char *err);

/*int					create_server(t_env *env);*/
int					create_client(t_env *env);

void				ft_loop(t_env *env);
void				clean_fd(t_env *env);
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
int					push_str(char *msg, t_fd *client, char *cst_emitter);
void				ft_del(void *d, size_t s);

/*
**			ft_parse.c
*/
int					ft_parse(int ac, char **av, t_env *env);

#endif
