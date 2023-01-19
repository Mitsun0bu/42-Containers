# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 09:05:09 by llethuil          #+#    #+#              #
#    Updated: 2023/01/16 15:59:08 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                              ~~~ COLOR CODES ~~~                             #
#                                                                              #
# **************************************************************************** #

GREEN	:=	\033[32m
BLUE	:=	\033[34m
PINK	:=	\033[35m
END		:=	\033[0m

# **************************************************************************** #
#                                                                              #
#                              ~~~ VARIABLES ~~~                               #
#                                                                              #
# **************************************************************************** #

NAME		:=	containers

CC			:=	c++

CXXFLAGS	:=	 -Wall -Wextra -Werror
# -std=c++98
RM			:=	rm -f

OBJS_DIR	:=	.objs

SRCS_LST	:=	main.cpp	\

INCS_LST	:=	vector.hpp	\

OBJS_LST	:=	$(SRCS_LST:.cpp=.o)

OBJS		:=	$(addprefix $(OBJS_DIR)/, $(OBJS_LST))

# ************************************************************************** #
#                                                                            #
#                              ~~~ RULES & COMMANDS ~~~                      #
#                                                                            #
# ************************************************************************** #

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp $(INCS_LST) Makefile | $(OBJS_DIR)
	printf "$(BLUE)> Compiling :$(END) $<\n"
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	printf "$(PINK)> Removing $(NAME) .o files ...$(END)\n"
	$(RM) $(OBJS)
	printf "$(PINK)> Removing .objs directory ...$(END)\n"
	rm -rf $(OBJS_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	printf "$(PINK)> Removing $(NAME) executable file ...$(END)\n"
	$(RM) $(NAME)
	$(RM) log.txt
	printf "$(GREEN)> $(NAME) executable file has been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean re