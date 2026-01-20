NAME = a.out

DIR_LIBFT = lib/libft/
LIBFT = $(DIR_LIBFT)libft.a

SRC = src/main.c 
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

