SRC = 
CC = cc
NAME = cub3D
FLAGS = -Wextra -Werror -Wall -lmlx -framework OpenGL -framework AppKit
HEADER = "\033[0;35m   █▀▀ █░░█ █▀▀▄ █▀▀█ █▀▀▄ \n   █░░ █░░█ █▀▀▄ ░░▀▄ █░░█ \n   ▀▀▀ ░▀▀▀ ▀▀▀░ █▄▄█ ▀▀▀░\033[0;0m"
FOOTER = "\033[0;35m➔\033[0;0m type \033[0;34m./cub3D\033[0;0m to run the game."

all: $(NAME) | footer

bonus: $(BNAME) | bfooter

header :
	@echo
	@echo $(HEADER)
	@echo

footer :
	@echo $(FOOTER)

$(NAME): $(SRC) | header
	@echo "\033[0;35m\033[1m────── making cub3D ──────\033[0;0m"
	@printf "\033[2m"
	$(CC) $(FLAGS) -o $(NAME) $(SRC)
	@echo "\033[0;0m"

clean: | header
	@echo "\033[0;35m\033[1m────── clean printf ──────\033[0;0m"
	@echo clean
	@echo "\033[0;0m"

fclean: clean | header
	@echo "\033[0;35m\033[1m────── fclean cub3D ──────\033[0;0m"
	@printf "\033[2m"
	rm -rf $(NAME)
	@echo "\033[0;0m"

re: fclean all

.PHONY: all clean fclean re