NAME = libftprintf.a
DIR_LIB = libft
LIB_NAME = libft.a
LIBFT = $(DIR_LIB)/$(LIB_NAME)

LIBFT_ABS = $(abspath $(LIBFT))
TMPDIR = .libtmp

SRCS = $(addsuffix .c, ft_printf ft_itoa_base ft_itoa_u)
OBJS := $(SRCS:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror
INCLUDES = $(addprefix -I, . $(DIR_LIB))
AR = ar rc
RM = rm -f

# Test variables
# TEST_NAME = test_printf
# TEST_SRC = main.c

.PHONY: all clean fclean re test debug $(DIR_LIB)

all: $(NAME)

$(LIBFT):
	make -C $(DIR_LIB)

$(NAME): $(OBJS) $(LIBFT)
	@# ensure libft is built
	make -C $(DIR_LIB)
	@# create temp dir, extract libft.a members, then archive them with our objects
	@mkdir -p $(TMPDIR); \
	cd $(TMPDIR); \
	ar x $(LIBFT_ABS); \
	# build a shell list of extracted object filenames prefixed by temp dir
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

# debug: compile a small runner linking libft directly (useful for local debugging)
debug: $(LIBFT)
	$(CC) $(CCFLAGS) -I. -I$(DIR_LIB) debug_main.c $(SRCS) $(LIBFT) -o debug_printf

# test: re $(NAME)
# 	$(CC) $(CCFLAGS) $(INCLUDES) $(TEST_SRC) -L. -lftprintf -L$(DIR_LIB) -lft -o $(TEST_NAME)
# 	./$(TEST_NAME)

