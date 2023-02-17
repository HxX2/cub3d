# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 19:58:45 by zlafou            #+#    #+#              #
#    Updated: 2023/02/17 22:10:06 by zlafou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

PARSING			= #parsing srcs

SRCS			= #srcs

OBJS			= $(SRCS:.c=.o)

CFLAGS			= -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit #-g -fsanitize=address

CC				= cc

VPATH 			= #dirs of all srcs

HEADER			= "\033[0;35m   █▀▀ █░░█ █▀▀▄ █▀▀█ █▀▀▄ \n   █░░ █░░█ █▀▀▄ ░░▀▄ █░░█ \n   ▀▀▀ ░▀▀▀ ▀▀▀░ █▄▄█ ▀▀▀░\033[0;0m"

FOOTER			= "\033[0;35m➔\033[0;0m type \033[0;34m./$(NAME)\033[0;0m to run the shell."

vpath $(SRCS) $(VPATH)

all: $(NAME) | footer

header :
	@echo
	@echo $(HEADER)
	@echo

footer :
	@echo $(FOOTER)

.c.o: 
	@sleep 0.003
	@printf "\33[2K\r\033[1mmaking object \033[0;34m➔\033[0;0m\033[0;35m $@ \033[0;0m"
	-@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): | header $(OBJS)
	@echo
	@echo
	@echo "\033[0;35m\033[1m────── making libft ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) -C src/libft/
	@$(MAKE) bonus -C src/libft/
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── making cub3d ──────\033[0;0m"
	@printf "\033[2m"
	$(CC) ${OBJS} $(CFLAGS) ./src/libft/libft.a -o ${NAME}
	@echo "\033[0;0"

clean: | header
	@echo "\033[0;35m\033[1m────── clean libft ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) clean -C src/libft/
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── clean cub3d ──────\033[0;0m"
	@printf "\033[2m"
	rm -rf $(OBJS)
	@echo "\033[0;0m"

fclean:	clean | header
	@echo "\033[0;35m\033[1m────── fclean libft ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) fclean -C src/libft/
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── fclean cub3d ──────\033[0;0m"
	@printf "\033[2m"
	rm -rf $(NAME)
	@echo "\033[0;0m"
				
re:	fclean all

.PHONY:	all clean fclean re cub3d
