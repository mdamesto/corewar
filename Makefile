#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 19:20:50 by mdamesto          #+#    #+#              #
#    Updated: 2017/01/18 18:00:41 by mdamesto         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ASM	=	./asm_src/
COREWAR	=	./corewar_src/
LIB	=	./libft/

#MAKE	=	make -C

all:
		$(MAKE)	-C $(LIB)
		$(MAKE) -C $(ASM)
		$(MAKE) -C $(COREWAR)
clean:
		$(MAKE)	$(LIB) clean
		$(MAKE) $(ASM) clean
		$(MAKE) $(COREWAR) clean
fclean:
		$(MAKE)	$(LIB) fclean
		$(MAKE) $(ASM) fclean
		$(MAKE) $(COREWAR) fclean
re:		fclean all

norme:
	$(MAKE)	$(LIB) norme
	$(MAKE) $(ASM) norme
	$(MAKE) $(COREWAR) norme
	
.PHONY:		re all fclean clean norme
