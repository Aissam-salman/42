NAME = ft_ls

# LIBFT SOURCES
DIR_LIBFT = libft/
LIBFT = $(DIR_LIBFT)libft.a

SRCS = $(addprefix src/, main.c)
OBJS := $(SRCS:%.c=%.o)


CC = cc
CCFLAGS = -Wextra -Wall -Werror
DEBUG_FLAGS = -fsanitize=address -g
CCIFLAGS = -Iincludes -I$(DIR_LIBFT)includes

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CCFLAGS) $(CCIFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(DIR_LIBFT)

%.o: %.c
	$(CC) $(CCFLAGS) $(CCIFLAGS) -o $@ -c $<

debug:
	$(CC) $(CCFLAGS) $(CCIFLAGS) $(DEBUG_FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS_ALL)
	make clean -C $(DIR_LIBFT)

fclean: clean
	@rm -f $(NAME)
	make fclean -C $(DIR_LIBFT)

re: fclean all
