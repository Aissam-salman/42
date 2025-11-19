NAME = libft.a

SRCS = $(addsuffix .c, get_next_line get_next_line_utils)
OBJS := $(SRCS:%.c=%.o)

# BONUS_SRC = $(addsuffix _bonus.c, ft_lstnew ft_lstadd_front \
ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap)
# BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)
OBJS_ALL = $(OBJS) $(BONUS_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)
	$(RANNAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS_ALL) 

fclean: clean
	rm -f $(NAME)

re: fclean all

# bonus: $(BONUS_OBJS)
# 	$(ARNAME) $(BONUS_OBJS)
# 	$(RANNAME)
