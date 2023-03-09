# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 19:58:45 by zlafou            #+#    #+#              #
#    Updated: 2023/03/09 16:53:58 by gkarib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

PARSING			= utils_parsing.c valid_file.c convert_file.c component.c check_walls.c direction.c colors.c parse.c

UTILS			= mem.c ray_utils.c gl_utils.c primitives.c

GAME			= events.c init.c raycasting.c 3d_projection.c minimap.c vh_rays.c hook_events.c

SRCS			= cub3d.c $(PARSING) $(GAME) $(UTILS)

OBJS			= $(SRCS:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

MLX				= -lmlx -framework OpenGL -framework AppKit

VPATH 			= src/Parsing:src/game:src/utils

HEADER			= "\033[0;35m   █▀▀ █░░█ █▀▀▄ █▀▀█ █▀▀▄ \n   █░░ █░░█ █▀▀▄ ░░▀▄ █░░█ \n   ▀▀▀ ░▀▀▀ ▀▀▀░ █▄▄█ ▀▀▀░\033[0;0m"

FOOTER			= "\033[0;35m➔\033[0;0m type \033[0;34m./$(NAME)\033[0;0m to run the game."

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
	$(CC) ${OBJS} $(CFLAGS) $(MLX) ./src/libft/libft.a -o ${NAME}
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
