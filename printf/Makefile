# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 18:22:26 by lufiguei          #+#    #+#              #
#    Updated: 2024/05/02 18:26:31 by lufiguei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

CC = cc
RM = rm -rf

SRC = ft_printf.c\
	ft_putstr.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putptr.c\
	ft_puthex.c\
	ft_unsint.c\
	ft_atoi.c\
	ft_strlen.c\

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
