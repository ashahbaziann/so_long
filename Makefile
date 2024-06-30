NAME = so_long

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SRCS =  main.c \
	map_character.c \
	split.c \
	utils.c \
	validation.c \
	walls.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) so_long.h gnl/get_next_line.h Makefile
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
