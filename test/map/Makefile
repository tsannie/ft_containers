# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 13:34:12 by tsannie           #+#    #+#              #
#    Updated: 2021/11/25 12:43:49 by tsannie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= ft.map.test.out
NAME2		= std.map.test.out
CC			= @clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= @rm -rf

BLACK		:= $(shell tput -Txterm setaf 0)
RED			:= $(shell tput -Txterm setaf 1)
GREEN		:= $(shell tput -Txterm setaf 2)
YELLOW		:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
PURPLE		:= $(shell tput -Txterm setaf 5)
BLUE		:= $(shell tput -Txterm setaf 6)
WHITE		:= $(shell tput -Txterm setaf 7)
BOLD		:= $(shell tput -Txterm bold)
END			:= $(shell tput -Txterm sgr0)

SRC			= constructor.test.cpp main.test.cpp \
			 capacity.test.cpp all_it.test.cpp \
			 element_access.test.cpp

all:		test

$(NAME1):
			$(CC) $(CFLAGS) $(SRC) -D pl=ft -o $(NAME1)
			@echo "${GREEN}The $(BOLD)${YELLOW}$(NAME1)${END}${GREEN} has been build !${END}"


$(NAME2):
			$(CC) $(CFLAGS) $(SRC) -D pl=std -o $(NAME2)
			@echo "${GREEN}The $(BOLD)${YELLOW}$(NAME2)${END}${GREEN} has been build !${END}"

test:
			$(RM) res
			@$(MAKE) $(NAME1)
			@$(MAKE) $(NAME2)
			@mkdir res
			@mv $(NAME1) res/
			@mv $(NAME2) res/
			@./res/$(NAME1) &> res/ft.res
			@./res/$(NAME2) &> res/std.res
			@-diff -u res/ft.res res/std.res > res/diff.res

fclean:
			$(RM) res
			@echo "${LIGHTPURPLE}Delete $(NAMEC)${LIGHTPURPLE} ...${END}\n"

re:			fclean all

.PHONY:		all test clean fclean re
