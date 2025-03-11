# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 18:15:50 by pibreiss          #+#    #+#              #
#    Updated: 2025/03/05 05:25:55 by pibreiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = gcc
CFLAGS = -Werror -Wextra -Werror

SRC_CLIENT = src/client.c src/minitalk_utils.c ft_printf/*.c
SRC_SERVER = src/server.c ft_printf/*.c
SRC_PRINTF = ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c \
			ft_printf/ft_putstr.c ft_printf/ft_putexa.c ft_printf/ft_putptr.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o) $(SRC_PRINTF:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o) $(SRC_PRINTF:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

INCLUDES = -I includes -I ft_printf

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_PRINTF) -o $(NAME_CLIENT) $(INCLUDES)

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_PRINTF) -o $(NAME_SERVER) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_PRINTF)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re