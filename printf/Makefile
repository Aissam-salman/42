NAME = libftprintf.a
DIR_LIB = libft
LIB_NAME = libft.a
LIBFT = $(DIR_LIB)/$(LIB_NAME)

LIBFT_ABS = $(abspath $(LIBFT))
TMPDIR = .libtmp

SRCS = $(addsuffix .c, ft_printf ft_itoa_u ft_puthexa ft_puthexa_p_fd \
	ft_print_str ft_print_nbr ft_print_nbr_u ft_putchar_len)
OBJS := $(SRCS:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror
INCLUDES = -I. -I$(DIR_LIB)
AR = ar rc
RM = rm -f

# Test variables
# TEST_NAME = test_printf
# TEST_SRC = main.c

.PHONY: all clean fclean re
all: $(NAME)

$(LIBFT):
	make -C $(DIR_LIB)

$(NAME): $(OBJS) $(LIBFT)
	make -C $(DIR_LIB)
	mkdir -p $(TMPDIR); \
	(cd $(TMPDIR) && ar x $(LIBFT_ABS)); \
	# pour chaque ligne, remplace le début (^) par $(TMPDIR)/
	list=`ar t $(LIBFT_ABS) | sed 's|^|$(TMPDIR)/|'`; \
	$(AR) $(NAME) $(OBJS) $$list; \
	ranlib $(NAME); \
	rm -rf $(TMPDIR)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	make -C $(DIR_LIB) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)
	make -C $(DIR_LIB) fclean

re: fclean all

# debug: $(LIBFT)
# 	$(CC) $(CCFLAGS) -I. -I$(DIR_LIB) $(TEST_SRC) $(SRCS) $(LIBFT) -o $(TEST_NAME)


