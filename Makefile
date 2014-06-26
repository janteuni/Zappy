# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/18 13:00:58 by bgronon           #+#    #+#              #
#    Updated: 2014/06/26 16:41:10 by bgronon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRV = serveur
NAME_CLI = client
NAME_GFX = gfx

DIR_SRV = dir_serveur
DIR_CLI = dir_client
DIR_GFX = dir_gfx

.SILENT:

all: $(NAME_SRV) $(NAME_CLI) $(NAME_GFX)

$(NAME_SRV):
	make -C $(DIR_SRV)
	/bin/rm -rf $(NAME_SRV)
	ln -s $(DIR_SRV)/$(NAME_SRV) .

$(NAME_CLI):
	make -C $(DIR_CLI)
	/bin/rm -rf $(NAME_CLI)
	ln -s $(DIR_CLI)/$(NAME_CLI) .

$(NAME_GFX):
	if ! [ -a gfx.app ] ; \
	then \
		cd $(DIR_GFX) && \
		npm install && \
		rm -rf ./build/releases && \
		./node_modules/.bin/bower install && \
		./node_modules/.bin/grunt build && \
		ln -sF ./$(DIR_GFX)/build/releases/Threepy.js/mac/Threepy.js.app ../gfx.app && \
		printf "\e[32m------------------------------------------------------\e[0m\n" && \
		printf "\e[34mGraphic compiled.\e[0m\n" && \
		printf "\e[32m------------------------------------------------------\e[0m\n"; \
	else \
		printf "\e[32m------------------------------------------------------\e[0m\n" && \
		printf "\e[34mGraphic already compiled.\e[0m\n" && \
		printf "\e[32m------------------------------------------------------\e[0m\n"; \
	fi

clean :
	$(MAKE) -C $(DIR_SRV) $@
	$(MAKE) -C $(DIR_CLI) $@

fclean : clean
	/bin/rm -rf $(NAME_SRV)
	/bin/rm -rf $(NAME_CLI)
	$(MAKE) -C $(DIR_SRV) $@
	$(MAKE) -C $(DIR_CLI) $@

re : fclean all

.PHONY: libft dir_serveur dir_client
