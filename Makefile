# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 13:23:19 by lufiguei          #+#    #+#              #
#    Updated: 2024/07/12 13:23:20 by lufiguei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g

S_NAME = server
C_NAME = client
PRINTF = printf/libftprintf.a

CC = cc
RM = rm -rf

S_SRC = server.c
S_OBJ = $(S_SRC:.c=.o)

C_SRC = client.c
C_OBJ = $(C_SRC:.c=.o)

S_BONUS = server_bonus
C_BONUS = client_bonus

S_BONUS_SRC = server_bonus.c
S_BONUS_OBJ = $(S_BONUS_SRC:.c=.o)

C_BONUS_SRC = client_bonus.c
C_BONUS_OBJ = $(C_BONUS_SRC:.c=.o)

all: $(PRINTF) $(S_NAME) $(C_NAME)

$(PRINTF):
	$(MAKE) -C printf

$(S_NAME): $(S_OBJ) $(PRINTF) 
	$(CC) $(CFLAGS) $(S_OBJ) -o $(S_NAME) $(PRINTF)
	
$(C_NAME): $(C_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME) $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(PRINTF) $(S_BONUS) $(C_BONUS)

$(S_BONUS): $(S_BONUS_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(S_BONUS_OBJ) -o $(S_BONUS) $(PRINTF)
	
$(C_BONUS): $(C_BONUS_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(C_BONUS_OBJ) -o $(C_BONUS) $(PRINTF)

clean:
	$(RM) $(S_OBJ) $(S_BONUS_OBJ) $(C_OBJ) $(C_BONUS_OBJ)
	
fclean: clean
	$(RM) $(S_NAME) $(C_NAME) $(S_BONUS) $(C_BONUS)
	$(MAKE) -C printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
