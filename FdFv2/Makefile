NAME = fdf

LIBFT = libft.a
DIR_LIBFT = lib/libft/

MINILIBX = libmlx_Linux.a
DIR_MINILIBX = lib/minilibx-linux/

SRC = $(addprefix src/, $(addsuffix .c, main ft_linked_list))
OBJS := $(SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror
INC_DIR = includes
CCIFLAGS = -I$(INC_DIR) -I$(DIR_LIBFT) -I$(DIR_MINILIBX)
MLX_FLAGS = -lXext -lX11 -lm -lz
#MATH flags
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CCIFLAGS) $(OBJS) \
	$(DIR_LIBFT)$(LIBFT) \
	$(DIR_MINILIBX)$(MINILIBX) \
	$(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(DIR_LIBFT)

$(MINILIBX):
	make -C $(DIR_MINILIBX) CC="gcc -std=gnu89"

%.o: %.c
	$(CC) $(CCIFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_MINILIBX)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(DIR_LIBFT)

re: fclean all

