# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 19:16:28 by pibreiss          #+#    #+#              #
#    Updated: 2025/02/27 19:18:13 by pibreiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_putexa.c ft_putptr.c

OBJS = $(SRC:%.c=%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all