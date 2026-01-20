NAME = fractol

DIR_LIBFT = lib/libft/
LIBFT = $(DIR_LIBFT)libft.a

DIR_MINILIBX = lib/minilibx-linux/
MINILIBX = $(DIR_MINILIBX)libmlx_Linux.a

SRC = src/main.c src/error.c src/init.c src/utils.c \
	  src/color.c src/compute.c src/key_handler.c \
	  src/render.c src/palette.c
OBJS := $(SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -O
INC_DIR = includes
CCIFLAGS = -I$(INC_DIR) -I$(DIR_MINILIBX)
RM = rm -f
MLX_FLAGS = -lXext -lX11 -lm -lz

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CCIFLAGS) $(OBJS) \
	$(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)

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
	$(RM) $(MINILIBX)
	make fclean -C $(DIR_LIBFT)

re: fclean all

