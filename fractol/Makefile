NAME = fractol

LIBFT = libft.a
DIR_LIBFT = lib/libft/

MINILIBX = libmlx_Linux.a
DIR_MINILIBX = lib/minilibx-linux/

SRC = $(addprefix src/, $(addsuffix .c, main))
OBJS := $(SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
INC_DIR = includes
CCIFLAGS = -I$(INC_DIR) -I$(DIR_MINILIBX)
RM = rm -f
MLX_FLAGS = -lXext -lX11 -lm -lz

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
	make -C $(DIR_MINILIBX)

%.o: %.c
	$(CC) $(CCIFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_MINILIBX)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DIR_MINILIBX)/$(MINILIBX)
	make fclean -C $(DIR_LIBFT)

re: fclean all

