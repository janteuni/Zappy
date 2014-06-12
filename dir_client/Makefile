# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbeck <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/06 16:16:30 by fbeck             #+#    #+#              #
#    Updated: 2014/06/12 18:28:03 by fbeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= client

CC					= clang
FLAG				= -Wall -Werror -Wextra -pedantic
INCS				= -I inc -I ./inc -I ../libft/inc
LIBS				= -L ../libft -lft

SRC					= $(DIR_SRC)/main.c \
					  $(DIR_SRC)/create_client.c \
					  $(DIR_SRC)/error.c \
					  $(DIR_SRC)/get_env.c \
					  $(DIR_SRC)/ft_parse.c \
					  $(DIR_SRC)/ft_loop.c \
					  $(DIR_SRC)/ft_look.c \
					  $(DIR_SRC)/ft_get_inventory.c \
					  $(DIR_SRC)/ft_recv.c \
					  $(DIR_SRC)/ft_send_cmd.c \
					  $(DIR_SRC)/ft_elevation.c \
					  $(DIR_SRC)/ft_move.c \
					  $(DIR_SRC)/ft_dead.c \
					  $(DIR_SRC)/ft_message.c \
					  $(DIR_SRC)/ft_ia.c \

# ---------------------------------------------------------------------------- #

DIR_LIST			= src
DIR_SRC				= src
DIR_INC				= inc
DIR_OBJ				= .obj

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# ---------------------------------------------------------------------------- #

all: libft $(NAME)

libft:
	@$(MAKE) -C ../libft

$(addprefix $(DIR_OBJ)/, %.o): %.c $(DIR_INC)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(FLAG) $(INCS) -o $@ -c $<
	@printf "\e[32m[✔]\e[0m\n"

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

$(DIR_OBJ) :
	@/bin/mkdir $(DIR_OBJ); \
	for DIR in $(DIR_LIST); \
	do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
	done

clean:
	@$(MAKE) -C ../libft $@
	@/bin/rm -rf $(DIR_OBJ);
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@$(MAKE) -C ../libft $@
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

debug : FLAG += -g3 -fno-inline -DD_ERRORS_ON
debug : re
	@printf '\033[1;31m%s\033[0m\n' "Debug enabled."

.PHONY: clean fclean re debug libft
