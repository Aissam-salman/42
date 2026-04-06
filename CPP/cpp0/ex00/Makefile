
NAME = megaphone

SRCS = megaphone.cpp
OBJS = $(SRCS:%.cpp=%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# INC_DIR = includes
# CCIFLAGS = -I(INC_DIR)
RM = rm -f

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(GREEN)COMPILE DONE !$(RESET)"

%.o:%c
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
