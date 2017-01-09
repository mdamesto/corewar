#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 19:20:50 by mdamesto          #+#    #+#              #
#    Updated: 2016/02/14 16:35:29 by mdamesto         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ../lib/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./
SRC_NAME =	ft_isascii.c ft_memcmp.c ft_strcmp.c ft_strncmp.c ft_toupper.c\
			ft_isdigit.c ft_memcpy.c ft_strcpy.c ft_strncpy.c ft_atoi.c\
			ft_isprint.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_bzero.c\
			ft_memalloc.c ft_memset.c ft_strlcat.c ft_strrchr.c ft_isalnum.c\
			ft_memccpy.c ft_strcat.c ft_strlen.c ft_strstr.c ft_isalpha.c\
			ft_memchr.c ft_strchr.c ft_strncat.c ft_tolower.c ft_itoa.c\
			ft_putnbr_fd.c ft_striteri.c ft_strsub.c ft_memalloc.c ft_putstr.c\
			ft_strjoin.c ft_strtrim.c ft_memdel.c ft_putstr_fd.c ft_strmap.c\
			ft_putendl_fd.c ft_putchar.c ft_strclr.c ft_strmapi.c\
			ft_putchar_fd.c ft_strdel.c ft_strnequ.c ft_putendl.c ft_strequ.c\
			ft_strnew.c ft_putnbr.c ft_striter.c ft_strsplit.c ft_lstadd.c\
			ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstdel.c\
			ft_putnbr_base.c ft_itoa_base.c ft_itoa_base_u.c ft_ishex.c ft_strupper.c\
			get_next_line.c ft_str_isdigit.c ft_tab_realloc.c ft_tab_len.c ft_tab_free.c\
			ft_realloc.c ft_tab_print.c ft_tab_set.c ft_istr_set.c ft_itab_set.c\
			ft_itab_len.c ft_istrlen.c ft_strcut_beg.c ft_rmv_space.c ft_isspace.c ft_strsplit_space.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH= ../inc/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))


all: $(NAME)

$(NAME): $(OBJ)
		mkdir -p ../lib
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rmdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null

fclean:	clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
