NAME_S = server
NAME_C = client

SRC_C = $(addprefix src/client/, main.c)
SRC_S = $(addprefix src/server/, main.c)
OBJS_C := $(SRC_C:%.c=%.o)
OBJS_S := $(SRC_S:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror
INC_DIR = includes
CPPFLAGS = -I $(INC_DIR)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CCFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C): $(OBJS_C)
	$(CC) $(CCFLAGS) $(OBJS_C) -o $(NAME_C)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS_S) $(OBJS_C)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all
