NAME = ft_ls

# LIBFT SOURCES
DIR_LIBFT = libft/
LIBFT = $(DIR_LIBFT)libft.a

SRCS = $(addprefix src/, main.c)
OBJS := $(SRCS:%.c=%.o)


CC = cc
CCFLAGS = -Wextra -Wall -Werror
DEBUG_FLAGS = -fsanitize=address -g
CCIFLAGS = -Iincludes -I$(DIR_LIBFT)includes

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CCFLAGS) $(CCIFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

%.o: %.c
	$(CC) $(CCFLAGS) $(CCIFLAGS) -o $@ -c $<

debug: $(LIBFT) $(OBJS)
	$(CC) $(CCFLAGS) $(CCIFLAGS) $(DEBUG_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	$(MAKE) clean -C $(DIR_LIBFT)

fclean: clean
	@rm -f $(NAME)
	$(MAKE) fclean -C $(DIR_LIBFT)

re: fclean all

# DOCKER (Fedora, environnement de correction)
DOCKER_IMAGE = ft_ls-fedora
DOCKER_RUN = docker run --rm -v "$(CURDIR)":/ft_ls $(DOCKER_IMAGE)

docker-image:
	docker build -q -t $(DOCKER_IMAGE) .

docker: docker-image
	$(DOCKER_RUN) make re

docker-shell: docker-image
	docker run --rm -it -v "$(CURDIR)":/ft_ls $(DOCKER_IMAGE) bash

.PHONY: all clean fclean re debug docker-image docker docker-shell
