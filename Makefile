# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 18:15:50 by pibreiss          #+#    #+#              #
#    Updated: 2025/03/11 11:00:40 by pibreiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = gcc
CFLAGS = -Werror -Wextra -Werror

SRC_CLIENT = src/client.c src/minitalk_utils.c ft_printf/ft_printf.c \
			ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c \
			ft_printf/ft_putexa.c ft_printf/ft_putptr.c
SRC_SERVER = src/server.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c \
			ft_printf/ft_putstr.c ft_printf/ft_putexa.c ft_printf/ft_putptr.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)

%.o: %.c includes/minitalk.h ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re