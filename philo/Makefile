NAME = philo

SRC = src/action.c \
	src/init_data.c \
	src/main.c \
	src/memory.c \
	src/mutex.c \
	src/philo_routine.c \
	src/print.c \
	src/reaper.c \
	src/run.c \
	src/utils.c \
	src/utils2.c

OBJS := $(SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address -g
INC_DIR = includes
CCIFLAGS = -I$(INC_DIR)
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(CCIFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(CCIFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
