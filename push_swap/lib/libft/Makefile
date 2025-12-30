NAME = libft.a

# LIBFT SOURCES
SRCS = $(addprefix src/, $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii \
ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy \
ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr\
ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd \
ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_convert_base ft_atoi_base ft_itoa_base \
ft_swap ft_power ft_reverse ft_strndup get_next_line))

# PRINTF SOURCES
SRCS += $(addprefix src/printf/, $(addsuffix .c, ft_printf ft_itoa_u \
ft_print_nbr ft_print_str ft_putchar_len ft_puthexa_p_fd ft_puthexa ft_print_nbr_u))

OBJS := $(SRCS:%.c=%.o)

BONUS_SRC = $(addprefix src/, $(addsuffix _bonus.c, ft_lstnew ft_lstadd_front \
ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap))
BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror
INC_DIR = includes
CPPFLAGS = -I $(INC_DIR)
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)
OBJS_ALL = $(OBJS) $(BONUS_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(ARNAME) $(OBJS)
	@$(RANNAME)

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS_ALL)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	$(ARNAME) $(BONUS_OBJS)
	$(RANNAME)
