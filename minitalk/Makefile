NAME_S = server
NAME_C = client

LIBFT = libft.a
DIR_LIBFT = lib/libft/

SRC_C = $(addprefix src/client/, main.c)
SRC_S = $(addprefix src/server/, main.c)
OBJS_C := $(SRC_C:%.c=%.o)
OBJS_S := $(SRC_S:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror
CPPFLAGS = -Iincludes -Ilib/libft

all: $(LIBFT) $(NAME_S) $(NAME_C)

$(NAME_S): $(LIBFT) $(OBJS_S)
	$(CC) $(CCFLAGS) $(OBJS_S) $(DIR_LIBFT)$(LIBFT) -o $(NAME_S)

$(NAME_C): $(LIBFT) $(OBJS_C)
	$(CC) $(CCFLAGS) $(OBJS_C) $(DIR_LIBFT)$(LIBFT) -o $(NAME_C)

$(LIBFT):
	make -C $(DIR_LIBFT)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS_S) $(OBJS_C)
	make clean -C $(DIR_LIBFT)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)
	make fclean -C $(DIR_LIBFT)

re: fclean all
