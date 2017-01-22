#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 19:20:50 by mdamesto          #+#    #+#              #
#    Updated: 2017/01/18 18:02:55 by mdamesto         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ../corewar

SRC_NAME = main.c env.c error.c convert.c inst_tools.c get_champ.c parse_args.c\
		init_champs.c play_game.c exec_inst.c\
		i_live.c i_ld.c i_st.c i_add_sub.c i_and_or_xor.c
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj/

LIB_PATH = ../libft
LIB_NAMES = -lft
INC_PATH = ../inc/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = $(LIB) $(LIB_NAMES)
CC = gcc



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(LDFLAGS)

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

.PHONY: all clean fclean re norme
.NOTPARALLEL: re
