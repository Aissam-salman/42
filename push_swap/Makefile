NAME = push_swap
DIR_LIBFT = lib/libft/
LIBFT = $(DIR_LIBFT)libft.a

SRC = src/main.c src/linked_list.c src/parsing.c  \
	  src/utils.c src/core.c src/move.c src/move2.c \
	  src/finder.c src/sort_short.c src/handle_index.c \
	  src/ft_atoi_safe.c
OBJS := $(SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror
INC_DIR = includes
CCIFLAGS = -I$(INC_DIR)
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CCIFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(DIR_LIBFT)

%.o: %.c
	$(CC) $(CCIFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	make clean -C $(DIR_LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(DIR_LIBFT)

re: fclean all
