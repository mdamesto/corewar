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

ASM	=	./asm/
COREWAR	=	./corewar/
LIB	=	./libft/

MAKE	=	make -C

all:
		$(MAKE)	$(LIB)
		$(MAKE) $(ASM)
		$(MAKE) $(COREWAR)
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