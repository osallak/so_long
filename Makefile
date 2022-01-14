NAME = so_long
SRCS = so_long.c \
		map_checker/check_map_utils.c \
		map_checker/find_player.c \
		map_checker/general_map_check.c \
		map_checker/get_map_info.c \
		utils/utils.c \
		utils/get_next_line.c \
		game_play/move_player.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)
	@echo "███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗"
	@echo "██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝"
	@echo "███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗"
	@echo "╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║"
	@echo "███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝"
	@echo "╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝"
                                                         


$(NAME): $(OBJS)
	@cc $(CFLAGS) -o $(NAME) $^

%.o: %.c
	@cc $(CFLAGS) -c $^ -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
	