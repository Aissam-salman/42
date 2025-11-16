NAME = libftprintf.a

SRCS = $(addsuffix .c, ft_printf)
OBJS := $(SRCS:%.c=%.o)

# BONUS_SRC = $(addsuffix _bonus.c)
# BONUS_OBJS := $(BONUS_SRC:%.c=%.o)


CC = cc
CCFLAGS = -Wextra -Wall -Werror
INC_DIR = .
CPPFLAGS = -I $(INC_DIR)
ARNAME = ar rcs $(NAME)
# OBJS_ALL = $(OBJS) $(BONUS_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(ARNAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

# bonus: $(BONUS_OBJS)
# 	$(ARNAME) $(BONUS_OBJS)
# 	$(RANNAME)
