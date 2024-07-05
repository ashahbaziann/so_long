NAME = so_long

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SRCS =  main.c \
	map_character.c \
	split.c \
	utils.c \
	utils2.c \
	validation.c \
	walls.c \
	initialization.c \
	check_path.c \
	init_window.c \
	movement.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) so_long.h gnl/get_next_line.h Makefile
	cc $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
