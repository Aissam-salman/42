##
# targets
# #
# # # # #
NAME = libftprintf.a
DIR_LIB = libft
LIB_NAME = libft.a
LIBFT = $(DIR_LIB)/$(LIB_NAME)

SRCS = $(addsuffix .c, ft_printf)
OBJS := $(SRCS:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror
INCLUDES = $(addprefix -I, . $(DIR_LIB))
AR = ar rcs
RM = rm -f

# Test variables
TEST_NAME = test_printf
TEST_SRC = main.c

.PHONY: all clean fclean re test $(DIR_LIB)

#ACTIONS
all: $(NAME)

$(LIBFT):
	make -C $(DIR_LIB)

$(NAME): $(OBJS) $(LIBFT)
	make -C $(DIR_LIB)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

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

test: re $(NAME)
	$(CC) $(CCFLAGS) $(INCLUDES) $(TEST_SRC) -L. -lftprintf -o $(TEST_NAME)
	./$(TEST_NAME)

