# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 11:15:52 by rlandolt          #+#    #+#              #
#    Updated: 2023/04/27 13:50:45 by rlandolt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC = ft_printf.c \

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $@ $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
