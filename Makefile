# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcreux <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 05:29:33 by jcreux            #+#    #+#              #
#    Updated: 2019/02/24 19:37:22 by jcreux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = valid_line.c \
		 read.c \
		 array_maker.c \
		 check_array.c \
		 init_fillit.c \
		 len_square.c \
		 put_array_tetri.c \
		 size_tetri.c \
		 main.c

LIB = libft/

OBJS = $(SRCS:c=o)

all: $(NAME)

%.o : %.o
	$(CC) $(CFLAGS) -c -o $@ $^
$(NAME): lib $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIB)libft.a -I -o $(NAME)
	@echo Done.

lib:
	make -C $(LIB)

clean:
	rm -f $(OBJS)
	make -C $(lib) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean re all lib
