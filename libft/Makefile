NAME = libft.a
SRCS = $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii \
ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy)
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
	$(CC) $(CCFLAGS) main_test.c -L. -lft -o test
	@echo "Compile sucess !"
	./test

vide: fclean
	rm -f test
