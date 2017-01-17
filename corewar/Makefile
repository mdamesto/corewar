#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 19:20:50 by mdamesto          #+#    #+#              #
#    Updated: 2016/01/20 16:25:36 by mdamesto         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

SRC_NAME = main.c env.c error.c convert.c
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj/

LIB_PATH = ../lib/
LIB_NAMES = -lft
INC_PATH = ../inc/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = $(LIB) $(LIB_NAMES)
CC = gcc



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIB) $(INC) $^ -o $@ $(LIB_NAMES)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rmdir $(OBJ_PATH) 2>/dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette ../inc/corewar.h