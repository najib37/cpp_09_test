# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nramadan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 17:20:46 by nramadan          #+#    #+#              #
#    Updated: 2022/12/23 15:34:01 by nramadan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =  c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	rpn.cpp

NAME = RPN

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
