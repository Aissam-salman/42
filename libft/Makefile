/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:59:59 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/05 13:00:23 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = libft.a
SRCS = $(addsuffix .c, ft_putchar ft_putstr ft_strcmp ft_strlen ft_swap)
OBJS := $(SRCS:%.c=%.o)
CC = cc
CCFLAGS = -Wextra -Wall -Werror
INC_DIR = includes
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
