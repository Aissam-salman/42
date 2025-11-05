NAME = libft.a
SRCS = $(addsuffix .c, ft_isalpha ft_isdigit)
OBJS := $(SRCS:%.c=%.o)
CC = cc
CCFLAGS = -Wextra -Wall -Werror
INC_DIR = .
CPPFLAGS = -I $(INC_DIR)
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)
	$(RANNAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	$(CC) $(CCFLAGS) -L. -lft main_test.c -o test

vide: fclean
	rm -f test
