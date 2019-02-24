# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcreux <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 05:29:33 by jcreux            #+#    #+#              #
#    Updated: 2019/02/24 19:09:50 by jcreux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = array_maker.c count_tetri.c main.c read.c libft/ft*

OBJ = $(SRC:.c=.o)

all :  $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
