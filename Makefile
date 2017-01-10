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

NAME = asm

SRC_NAME = main.c error.c parsing.c env.c gnl.c label.c name_comment.c check_arg.c\
		inst_tools.c inst.c inst2.c
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj/

INC_PATH = ./inc/
LIB_NAME = libft.a
LIB_PATH = ./lib/
LIB_NAMES = -lft

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = $(LIB) $(LIB_NAMES)
CC = gcc



all: $(LIB_NAME) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIB) $(INC) $^ -o $@ $(LIB_NAMES)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	make clean -C ./libft/
	rm -f $(OBJ)
	rmdir $(OBJ_PATH) 2>/dev/null || true

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

$(LIB_NAME):
	make -C ./libft/

norme:
	make norme -C ./libft/
	norminette $(SRC)
	norminette $(INC_PATH)lem_in.h