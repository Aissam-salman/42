NAME = push_swap
LIBFT = libft.a
DIR_LIBFT = lib/libft/

SRC = $(addprefix src/, $(addsuffix .c, main linked_list parsing utils core))
OBJS := $(SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror
INC_DIR = includes
CCIFLAGS = -I$(INC_DIR)
#MATH flags
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CCIFLAGS) $(OBJS) \
	$(DIR_LIBFT)$(LIBFT) -o $(NAME)

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

