# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nramadan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 17:20:46 by nramadan          #+#    #+#              #
#    Updated: 2023/04/09 15:50:27 by nramadan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =  c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	btc.cpp \
		main.cpp

INC = btc.hpp

NAME = btc

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
