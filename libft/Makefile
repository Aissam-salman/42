NAME = libft.a
SRCS = $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii \
ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy \
ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr\
ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri)
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
	@echo "Compile sucess ! 👾"
	@echo "\n\n"

vide: fclean
	rm -f test a.out
