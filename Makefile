# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soel-hou <soel-hou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/03 10:26:27 by soel-hou          #+#    #+#              #
#    Updated: 2026/11/03 13:02:31 by soel-hou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

.PHONY: all clean fclean re

SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c ft_puthex.c ft_putptr.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
		cc -Wall -Wextra -Werror -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
