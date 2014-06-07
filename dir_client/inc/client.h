/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:37:54 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/07 18:18:45 by fbeck            ###   ########.fr       */
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

}					t_env;

t_env				*get_env(void);
int					error(char *err);
int					create_client(t_env *env);

/*
**			ft_parse.c
*/
int					ft_parse(int ac, char **av, t_env *env);

#endif
