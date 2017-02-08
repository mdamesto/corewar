./bjacob/doge.s                                                                                     000644  032017  010202  00000004324 13046414175 015121  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "Candy"
.comment ""

	st		r1, r12
	ld      %0 , r14
	zjmp    %:base

def:
	st		r9, -256
	st		r10, -256
	st		r14, -9
	st      r4, -21
	st      r14, -30
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st		r9, -256
	st		r10, -256
	st		r14, -9
	st      r4, -21
	st      r14, -30
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st		r10, -256
	st		r14, -9
	st      r4, -21
	st      r14, -30
	ld      %0 , r15
	zjmp %:def

liv:
	live    %42
	fork    %:live3
	ld      %0 , r16
	zjmp    %:base

base:
	live 	%42
	ld		%57672449, r3
	ld		%57672959, r4
	ld		%42991616, r9
	ld		%235536380, r10
	ld		%16777216 ,r11
	xor		r12, r14, r15
	sti		r15, %:live1, %1
	sti		r15, %:liv, %1
	sti		r15, %:live2, %1
	zjmp    %:live1

live1:
	live	%42
	fork	%:def
	fork	%:save
	ld		%0 , r15
	zjmp	%:liv

live3:
	st      r3, 256
	st      r3, 256
	st      r3, 256
	live %1
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
zjmp %:live3

attak:
	live 	%42
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
zjmp %:attak

live2:
		live    %1
save:
		live %1
		fork	%:attak
		st      r4, 254
		zjmp %:save
                                                                                                                                                                                                                                                                                                            ./brandazz/Rainbow_dash.s                                                                           000644  032017  010202  00000000154 13046414175 017173  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         ;basic.s

.name		"basic"
.comment	"this is a basic stuff"

loop:
	st r1, 6
	live %0
	ld %0, r2
	zjmp %:loop
                                                                                                                                                                                                                                                                                                                                                                                                                    ./cdivry/youforkmytralala.s                                                                         000644  032017  010202  00000006072 13046414175 017672  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name		"Oh, You Fork my TRALALA ..."
.comment	"HMMMM, my ding-ding-dong !!"

# LD : charge la valeur du 1er param dans le registre

# ST : stocke la valeur du registre vers le second paramètre.

# ADD : Additionne les 2 premiers registres, et met le résultat dans le 3eme.

# SUB : Soustrait les 2 premiers registres, et met le résultat dans le 3eme.

# AND : Applique un & (ET bit-a-bit) sur les 2 premiers registres, et met le 
# résultat dans le 3eme.

# OR : Applique un OU (bit-a-bit) sur les 2 premiers registres, et met le 
#résultat dans le troisième.

# XOR : Fait un OU exclusif bit a bit (c'est comme un OU normal, mais 1^1 = 0)

# ZJMP : saute a l'adresse si le carry est a 1.

# LDI : additionne les 2 premiers, traite ca comme une adresse, y lit une valeur
# de la taille d’un registre et la met dans le 3eme.

# STI  : additionne les 2 derniers, utilise cette somme comme une adresse ou 
# sera copiee la valeur du 1er param

# FORK : Crée un nouveau processus, qui hérite des diﬀérents états de son père,
 # à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).

# LLD : similaire a ld sans la restriction de IDX_MOD (ici 512) (a confirmer)

# LLDI : Pareil que ldi, mais n’applique aucun modulo aux adresses.

# LFORK : Pareil qu’un fork sans modulo à l'adresse.

# AFF : affiche sur la sortie standard le char ASCII

entry:
	st		r1, 6
	st		r1, r3
	live	%42
	fork	%:hanibalsmith
	zjmp	%:move1

hanibalsmith:
	live	%42
	st		r15, -50
	st		r15, -64
	st		r15, -78
	st		r15, -92
	st		r15, -106
	st		r15, -120
	st		r15, -134
	st		r15, -148
	st		r15, -162
	st		r15, -176
	st		r15, -190
	st		r15, -204
	st		r15, -218
	st		r15, -232
	st		r15, -246
	st		r15, -260
	st		r15, -274
	st		r15, -288
	st		r15, -302
	st		r15, -318
	st		r15, -332
	st		r15, -346
	st		r15, -360
	st		r15, -374
	st		r15, -388
	st		r15, -402
	st		r15, -416
	st		r15, -430
	st		r15, -444
	st		r15, -458
	st		r15, -472
	st		r15, -486
	st		r15, -500
	st		r16, 1
	live	%42
	fork	%:hanibalsmith
	zjmp	%:hanibalsmith

forking:
	live	%898
	fork	%:move2
	live	%1892
	fork	%:move2
	live	%4024
	fork	%:move2
	live	%232
	fork	%:move2

move1:
	st		r1, 6
	live	%5
	fork	%:move1
	zjmp	%9

move2:
	st		r1, 6
	live	%42
	fork	%:move2
	zjmp	%1

move3:
	st		r1, 6
	live	%42
	fork	%:move3
	zjmp	%2

move4:
	st		r1, 6
	live	%7
	fork	%:move4
	zjmp	%3

move5:
	st		r1, 6
	live	%1
	fork	%:move5
	zjmp	%4

hanibalsmith2:
	live	%512
	st		r14, 1
	st		r14, -203
	st		r14, -406
	st		r14, -609
	st		r14, -803
	st		r14, -1006
	st		r14, -1209
	st		r14, -1403
	st		r14, -1606
	st		r14, -1809
	st		r14, -2003
	st		r14, -2206
	st		r14, -2409
	st		r14, -2603
	st		r14, -2806
	st		r14, -3009
	st		r14, -3203
	st		r14, -3406
	st		r14, -3609
	st		r14, -3803
	st		r14, -4006
	st		r14, -4209
	st		r14, -4403
	st		r14, -4606
	st		r14, -4809
	st		r14, -5003
	st		r14, -5206
	st		r14, -5409
	st		r14, -5603
	st		r14, -5806
	st		r14, -6009
	st		r14, -6203
	st		r14, -6406
	st		r14, -6609
	st		r14, -6803
	st		r14, -7006
	st		r14, -7209
	st		r14, -7403
	st		r14, -7606
	st		r14, -7809
	st		r14, -8003
	st		r1, 6
	live	%1
	zjmp	%:hanibalsmith2
	fork	%:hanibalsmith2
                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ./clafleur/big_feet.s                                                                               000644  032017  010202  00000005122 13046414175 016321  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    big_feet.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clafleur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/16 20:28:04 by clafleur          #+#    #+#              #
#    Updated: 2014/03/02 17:23:26 by clafleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "top defense plus plus"
.comment "la meilleure defense c'est d'avoir une bonne defense"

start:

start_piege:
ld		%-16, r5				# r2 = soustraction de start pr aller a r2 : carry a 1
ld		%-12, r4				# r4 = suite (soustraction de start pr aller a r3 : suite du carry)
ld		%-8, r6					# r6 = soustration de start pr aller a r10 : zjmp
ld		%150994944, r10			# r10 = zjmp
ld		%42991616, r2			# debut de carry a 1
ld		%256, r3				# suite du carry a 1
ld		%16, r16				# decrementation de start
ld		%12, r7					# r7 = addition de end pr aller a r7 : carry a 1
ld		%16, r9					# r9 = suite (addition de end pr aller a r9 : suite du carry)
ld		%20, r11				# r11 = addition de end pr aller a r11 : zjmp
ld		%23, r12				# compteur pour le nombres de pieges
ld		%1, r13
ld		%0, r8					# carry = 1
sti		r1, %:piege1, %1
sti		r1, %:piege2, %1
sti		r1, %:begin, %1
sti		r1, %:live, %1
fork	%:begin

piege1:							# while(1)
live	%118978653103279		# je suis en vie
sti		r2, %:start, r5 
sti		r3, %:start, r4
sti		r10, %:start, r6
sub		r5, r16, r5
sub		r4, r16, r4
sub		r6, r16, r6
sub		r12, r13, r12			# decrementation du compteur
zjmp	%:start_piege			# reviens en debut de boucle
ld		%0, r8					# carry = 1
zjmp	%:piege1				# reviens en debut de boucle

begin:
live 	%13371337
fork	%:piege1
live 	%42424242
fork	%:piege2
live 	%123456789
fork	%:begin
live	%08395432657
fork	%:live
zjmp	%:begin

live:
live	%23456789456780987
zjmp	%:begin

piege2:
live	%198562346853412
sti		r2, %:end, r7 
sti		r3, %:end, r9
sti		r10, %:end, r11
add		r7, r16, r7
add		r9, r16, r9
add		r11, r16, r11
sub		r12, r13, r12			# decrementation du compteur
zjmp	%:start_piege			# reviens en debut de boucle
ld		%0, r8					# carry = 1
zjmp	%:piege2				# reviens en debut de boucle

end:
                                                                                                                                                                                                                                                                                                                                                                                                                                              ./dcohen/loose.s                                                                                    000644  032017  010202  00000004006 13046414175 015341  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name		"loose"
.comment	"loooose"

start:
	lfork	%2048
	sti		r1, %:wall, %1
	sti		r1, %:loop_live, %1
	sti		r1, %:loop_live, %16
	sti		r1, %:next_wall, %1
	st		r2, -14
	st		r2, -13

wall:
	live	%53165
	st		r2, -10
	st		r2, -15
	st		r2, -24
	st		r2, -33
	st		r2, -42
	st		r2, -51
	st		r2, -60
	st		r2, -69
	st		r2, -78
	st		r2, -87
	st		r2, -96
	st		r2, -105
	st		r2, -114
	st		r2, -123
	st		r2, -132
	st		r2, -141
	st		r2, -150
	st		r2, -159
	st		r2, -168
	st		r2, -177
	st		r2, -186
	st		r2, -195
	st		r2, -204
	st		r2, -213
	st		r2, -222
	st		r2, -231
	st		r2, -240
	st		r2, -249
	st		r2, -258
	st		r2, -267
	st		r2, -276
	st		r2, -285
	st		r2, -294
	st		r2, -303
	st		r2, -312
	st		r2, -321
	st		r2, -330
	st		r2, -339
	st		r2, -348
	st		r2, -357
	st		r2, -366
	st		r2, -375
	st		r2, -384
	st		r2, -393
	st		r2, -402
	st		r2, -411
	st		r2, -420
	st		r2, -429
	st		r2, -438
	st		r2, -447
	st		r2, -456
	st		r2, -465
	st		r2, -474
	st		r2, -483
	st		r2, -492
	st		r2, -501
	st		r2, -510
	zjmp	%:wall
	ld		%0, r2

loop_live:
	live	%654664
	ld		%0, r2
	fork	%:wall
	live	%354534
	fork	%:next_wall
	zjmp	%:loop_live

next_wall:
	live	%65468435
	ld		%0, r2
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	st		r2, 511
	zjmp	%:next_wall



#	ld		%251883523, r2
#	ld      %386101251, r3
#	st		r2, 15
#	st		r3, -1

#	st		r2, 15
#	st		r3, -1
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ./ekocevar/mandragore.s                                                                             000644  032017  010202  00000002426 13046414175 016702  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name		"mandragore"
.comment	"you can see me, you can't anymore, you can, you can't !"

entry:
	sti		r1, %:fwall, %1
	sti		r1, %:petale, %1
	fork	%:petale
	sti		r1, %:spore, %1
	ld		%0, r2

fwall:
	live	%569092
	st		r2, -24
	st		r2, -33
	st		r2, -42
	st		r2, -51
	st		r2, -60
	st		r2, -69
	st		r2, -78
	st		r2, -87
	st		r2, -96
	st		r2, -105
	st		r2, -114
	st		r2, -123
	st		r2, -132
	st		r2, -141
	st		r2, -150
	st		r2, -159
	st		r2, -168
	st		r2, -177
	st		r2, -186
	st		r2, -195
	st		r2, -204
	st		r2, -213
	st		r2, -222
	st		r2, -231
	st		r2, -240
	st		r2, -249
	st		r2, -258
	st		r2, -267
	st		r2, -276
	st		r2, -285
	st		r2, -294
	st		r2, -303
	st		r2, -312
	st		r2, -321
	st		r2, -330
	st		r2, -339
	st		r2, -348
	st		r2, -357
	st		r2, -366
	st		r2, -375
	st		r2, -384
	st		r2, -393
	st		r2, -402
	st		r2, -411
	st		r2, -420
	st		r2, -429
	st		r2, -438
	st		r2, -447
	st		r2, -456
	st		r2, -465
	st		r2, -474
	st		r2, -483
	st		r2, -492
	st		r2, -501
	st		r2, -510
	ld		%0, r2
	zjmp	%:fwall

petale:
	live	%235894
	fork	%:petale
	zjmp	%:feuille

spore:
	live	%265924
	fork	%:petale
	zjmp	%:petale

second_entry:
	sti r1, %:feuille, %1
	ld	%1, r3
	ld	%512, r5
	ld  %1024, r7

tige:
	add	r6, r3, r6
	zjmp	%:spore

feuille:
	live	%568724
	add	r6, r5, r7
	sti r7, r5, r7
	fork	%:petale
	zjmp	%:tige
                                                                                                                                                                                                                                          ./esusseli/gedeon.s                                                                                 000644  032017  010202  00000002112 13046414175 016051  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name		"Gédéon le Cochon"
.comment	"Tout est bon dans Gédéon"

tmp:
	sti		r1, %:youshallnotpass, %1
	sti		r1, %:core, %1
	sti		r1, %:core, %9
	sti		r1, %:core, %17
	sti		r1, %:core, %25
	sti		r1, %:live1, %1
	sti		r1, %:live2, %1
	sti		r1, %:youshallnotpass2, %1
	ld		%0, r1
	fork	%:core

trap:
	ld		%0, r1

youshallnotpass:
	live	%1337
	st		r1, -16
	st		r1, -25
	st		r1, -34
	st		r1, -43
	st		r1, -52
	st		r1, -61
	st		r1, -70
	st		r1, -79
	st		r1, -88
	st		r1, -97
	st		r1, -106
	st		r1, -115
	st		r1, -124
	st		r1, -133
	st		r1, -142
	st		r1, -151
	st		r1, -160
	st		r1, -410
	st		r1, -411
	st		r1, -412
	st		r1, -413
	st		r1, -414
	st		r1, -425
	st		r1, -416
	st		r1, -417
	st		r1, -418
	st		r1, -419
	ld		%0, r1
	zjmp	%:youshallnotpass

core:
	live	%1337
	fork	%:youshallnotpass
	live	%1337
	fork	%:youshallnotpass2
	live	%1337
	fork	%:live1
	live	%1337
	fork	%:core
	#ld		%0, r1
	zjmp	%:core

live1:
	live	%1337
	fork	%:live1
	ld		%0, r1

live2:
	live	%1337
	zjmp	%:live2

youshallnotpass2:
	live	%1337
	st		r1, 30
	st		r1, 29
	st		r1, 28
	st		r1, 27
	ld		%0, r1
	zjmp	%:youshallnotpass2
                                                                                                                                                                                                                                                                                                                                                                                                                                                      ./evlasova/terminator.s                                                                             000644  032017  010202  00000001671 13046414175 016771  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "terminator"
.comment "Hasta la vista, baby!"

live:
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10

protection:
			  zjmp %:live
	          ld %25, r4
	          st r4, -500
	          st r4, -500
		      st r4, -500
	          st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
	          st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
	          st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
	          zjmp %:protection
                                                                       ./fcorre/ultimate-surrender.s                                                                       000644  032017  010202  00000010657 13046414175 020104  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "Ultimate Surrender"
.comment "Y'en a qui vont prendre cher... :)"

ld %0, r2
zjmp %:var170
var1:
lfork %:var1
var2:
lfork %:var1
var3:
lfork %:var1
var4:
lfork %:var1
var5:
lfork %:var1
var6:
lfork %:var1
var7:
lfork %:var1
var8:
lfork %:var1
var9:
lfork %:var1
var10:
lfork %:var1
var11:
lfork %:var1
var12:
lfork %:var1
var13:
lfork %:var1
var14:
lfork %:var1
var15:
lfork %:var1
var16:
lfork %:var1
var17:
lfork %:var1
var18:
lfork %:var1
var19:
lfork %:var1
var20:
lfork %:var1
var21:
lfork %:var1
var22:
lfork %:var1
var23:
lfork %:var1
var24:
lfork %:var1
var25:
lfork %:var1
var26:
lfork %:var1
var27:
lfork %:var1
var28:
lfork %:var1
var29:
lfork %:var1
var30:
lfork %:var1
var31:
lfork %:var1
var32:
lfork %:var1
var33:
lfork %:var1
var34:
lfork %:var1
var35:
lfork %:var1
var36:
lfork %:var1
var37:
lfork %:var1
var38:
lfork %:var1
var39:
lfork %:var1
var40:
lfork %:var1
var41:
lfork %:var1
var42:
lfork %:var1
var43:
lfork %:var1
var44:
lfork %:var1
var45:
lfork %:var1
var46:
lfork %:var1
var47:
lfork %:var1
var48:
lfork %:var1
var49:
lfork %:var1
var50:
lfork %:var1
var51:
lfork %:var1
var52:
lfork %:var1
var53:
lfork %:var1
var54:
lfork %:var1
var55:
lfork %:var1
var56:
lfork %:var1
var57:
lfork %:var1
var58:
lfork %:var1
var59:
lfork %:var1
var60:
lfork %:var1
var61:
lfork %:var1
var62:
lfork %:var1
var63:
lfork %:var1
var64:
lfork %:var1
var65:
lfork %:var1
var66:
lfork %:var1
var67:
lfork %:var1
var68:
lfork %:var1
var69:
lfork %:var1
var70:
lfork %:var1
var71:
lfork %:var1
var72:
lfork %:var1
var73:
lfork %:var1
var74:
lfork %:var1
var75:
lfork %:var1
var76:
lfork %:var1
var77:
lfork %:var1
var78:
lfork %:var1
var79:
lfork %:var1
var80:
lfork %:var1
var81:
lfork %:var1
var82:
lfork %:var1
var83:
lfork %:var1
var84:
lfork %:var1
var85:
lfork %:var1
var86:
lfork %:var1
var87:
lfork %:var1
var88:
lfork %:var1
var89:
lfork %:var1
var90:
lfork %:var1
var91:
lfork %:var1
var92:
lfork %:var1
var93:
lfork %:var1
var94:
lfork %:var1
var95:
lfork %:var1
var96:
lfork %:var1
var97:
lfork %:var1
var98:
lfork %:var1
var99:
lfork %:var1
var100:
lfork %:var1
var101:
lfork %:var1
var102:
lfork %:var1
var103:
lfork %:var1
var104:
lfork %:var1
var105:
lfork %:var1
var106:
lfork %:var1
var107:
lfork %:var1
var108:
lfork %:var1
var109:
lfork %:var1
var110:
lfork %:var1
var111:
lfork %:var1
var112:
lfork %:var1
var113:
lfork %:var1
var114:
lfork %:var1
var115:
lfork %:var1
var116:
lfork %:var1
var117:
lfork %:var1
var118:
lfork %:var1
var119:
lfork %:var1
var120:
lfork %:var1
var121:
lfork %:var1
var122:
lfork %:var1
var123:
lfork %:var1
var124:
lfork %:var1
var125:
lfork %:var1
var126:
lfork %:var1
var127:
lfork %:var1
var128:
lfork %:var1
var129:
lfork %:var1
var130:
lfork %:var1
var131:
lfork %:var1
var132:
lfork %:var1
var133:
lfork %:var1
var134:
lfork %:var1
var135:
lfork %:var1
var136:
lfork %:var1
var137:
lfork %:var1
var138:
lfork %:var1
var139:
lfork %:var1
var140:
lfork %:var1
var141:
lfork %:var1
var142:
lfork %:var1
var143:
lfork %:var1
var144:
lfork %:var1
var145:
lfork %:var1
var146:
lfork %:var1
var147:
lfork %:var1
var148:
lfork %:var1
var149:
lfork %:var1
var150:
lfork %:var1
var151:
lfork %:var1
var152:
lfork %:var1
var153:
lfork %:var1
var154:
lfork %:var1
var155:
lfork %:var1
var156:
lfork %:var1
var157:
lfork %:var1
var158:
lfork %:var1
var159:
lfork %:var1
var160:
lfork %:var1
var161:
lfork %:var1
var162:
lfork %:var1
var163:
lfork %:var1
var164:
lfork %:var1
var165:
lfork %:var1
var166:
lfork %:var1
var167:
lfork %:var1
var168:
var169:
var170:
st r4, -503
zjmp %:var225
var171:
lfork %:var1
var172:
lfork %:var1
var173:
lfork %:var1
var174:
lfork %:var1
var175:
lfork %:var1
var176:
lfork %:var1
var177:
lfork %:var1
var178:
lfork %:var1
var179:
lfork %:var1
var180:
lfork %:var1
var181:
lfork %:var1
var182:
lfork %:var1
var183:
lfork %:var1
var184:
lfork %:var1
var185:
lfork %:var1
var186:
lfork %:var1
var187:
lfork %:var1
var188:
lfork %:var1
var189:
lfork %:var1
var190:
lfork %:var1
var191:
lfork %:var1
var192:
lfork %:var1
var193:
lfork %:var1
var194:
lfork %:var1
var195:
lfork %:var1
var196:
lfork %:var1
var197:
lfork %:var1
var198:
lfork %:var1
var199:
lfork %:var1
var200:
lfork %:var1
var201:
lfork %:var1
var202:
lfork %:var1
var203:
lfork %:var1
var204:
lfork %:var1
var205:
lfork %:var1
var206:
lfork %:var1
var207:
lfork %:var1
var208:
var209:
var210:
var211:
var225:
st r1, 6
live %0
ld %57672449, r4				;ld %4278780395, r5
ld %4278780410, r5
ld %151088384, r3 ;st r4, 511
st r4, 511
st r5, 510
	;; st r3, 509
ld %0, r2
zjmp %494
                                                                                 ./gbir/_.s                                                                                          000644  032017  010202  00000004354 13046414175 014127  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "Underscore"
.comment "__UNDERSCORE_S__"

first:
	ld		%0, r2
	zjmp	%:begin
	zjmp	%-511
defdessus:
	live	%-42
	sti		r10, r11, r13
	add		r12, r13, r13
	xor		r13, %-255, r14
	zjmp	%:zero
	ld		%0, r14
	zjmp	%:defdessus
zero:
	ld		%0, r13
	zjmp	%:defdessus
#plein de truck pour remplir
lasertop:
	live	%-42
	ld		%-128, r6
	fork	%:lasera
	ld		%190056198, r7
	ld		%0, r5
	ld		%0, r16
	zjmp	%:laser
lasera:
	ld      %84541307, r7
	ld      %4, r5
	ld		%190056198, r16
dec1:
	st      r16, -490
dec2:
	st      r7, -491
laser:
	ld		%0, r2
	zjmp	%-511
empty:
	lldi    %42, %42, r16
#def du dessus
atj1:
	live	%-42
	sti		r1, %:defdessus, %1
	ld		%57672959, r10
	ld		%-30, r11
	ld		%-5, r12
	st		r1, 6
defplus:
	live	%-42
	fork	%:defdessus
	ld		%-165, r13
	ld		%0, r2
	zjmp	%:defplus
at2:
	sti		r1, %:li1, %1
	sti     r1, %:proc1, %1
	fork    %:atj1
	st      r1, 6
	live    %-42
	or		r1, r1, r7
	ld		%1880161814, r9
	ld      %1879571989, r10
	ld      %34209281, r11
#live + def dessous + attack
atf:
	fork	%:proc1
li1:
	live	%-42
	fork	%:head
	ld		%0, r2
	zjmp	%:brain
head:
	ld		%191104768, r7
	ld		%5, r6
	ld		%0, r2
	zjmp	%:forklive
proc1:
	live	%-42
	fork    %:tail
corps:
	ld      %101056768, r7
	ld      %9, r6
	ld      %0, r2
	zjmp    %:forklive
tail:
	ld      %0, r2
	ld      %12, r6
	ld      %0, r2
	zjmp    %:forklive
forklive:
	st		r1, 6
	live    %-42
	sti		r7, r6, %317
	ld		%0, r2
	zjmp	%309
beginnewattack:
	sti     r16, %:modme, %1
	fork	%:def_at
	ld      %24, r16
	sti     r16, %:modme, %1
	st      r1, 6
	live    %-42
golive:
	ld      %0, r2
	zjmp    %511
brain:
	ld		%16, r12
	add		r12, r9, r9
	add		r12, r10, r10
	add		r12, r11, r11
	st		r1, 6
	live	%-42
	ld		%0, r2
	sti		r1, %:lasertop, %1
	sti     r9, %:dec1, %1
	sti     r10, %:dec2, %1
	sti     r11, %:laser, %6
	fork	%:lasertop
	zjmp	%:atf
begin:
	ld		%16777216, r16
	sti		r16 ,%:first, %6
	st		r1, 117
	sti		r1, %:sst, %1
	ld		%507, r4
	ld		%507, r6
	st		r1, 6
	live	%-42
def_at:
	ld		%190055170, r8
	ld		%67699190, r9
	st		r8, 511
	st		r9, 510
modme:
	ld		%24, r8
	fork	%:at2
at1:
	fork	%:sjmp
sst:
	live	%-1
	ld		%0, r2
	ld		%190055682, r3
	ld		%190056194, r5
	ld		%190056194, r7
	ld		%0, r16
	zjmp	%448
sjmp:
	live	%0
	ld		%4, r2
	ld		%101253622, r3
	ld		%134807571, r5
	ld		%134807571, r7
	ld		%0, r16
	zjmp	%405
                                                                                                                                                                                                                                                                                    ./gjestin/salamahenagalabadoun.s                                                                    000644  032017  010202  00000002050 13046414175 020530  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    salamahenagalabadoun.s                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjestin <gjestin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/21 22:08:42 by gjestin           #+#    #+#              #
#    Updated: 2014/02/25 21:02:17 by gjestin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "salamahenagalabadoun"
.comment "sussKBO hin hin"

ld		32, r3
ld		4, r4
ld		190, r5
st		r1, 6
loop:
live	%666
sti		r5, r5, r3
add		r3, r4, r5
ld		%0, r16
zjmp	%:loop
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ./gleger/Machine-gun.s                                                                              000644  032017  010202  00000001612 13046414175 016360  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "Machine-gun"
.comment "yipikai mother fucker"

entry:	sti r1, %:live, %1
		
		ld	%0, r2
		live %10
		ld	%47, r3
		zjmp %:def

wall:	ld %70, r3
		zjmp %:wall2
		ld %15, r3
		ld	10, r4
		sub r3, r4, r3
		st r3, -162
		st r3, -173
		st r3, -184
		st r3, -195
		st r3, -206


live:	live %15
		zjmp %3

def:	st r2, -270
		zjmp %:wall
		st r2, -261
		st r2, -252
		st r2, -243
		st r2, -254
		st r2, -265
		st r2, -276
		st r2, -287
		st r2, -298
		st r2, -309
		st r2, -318
		st r2, -327
		st r2, -336
		st r2, -345
		st r2, -354
		st r2, -363
		st r2, -372
		st r2, -381
		st r2, -390
		zjmp %:def
		zjmp %:live

wall2:	live %130000
		st r5, 66
		st r5, 75
		st r5, 84
		st r5, 93
		st r5, 102
		st r5, 111
		st r5, 120
		st r5, 129
		st r5, 138
		st r5, 147
		st r5, 156
		st r5, 165
		st r5, 174
		st r5, 183
		st r5, 192
		st r5, 201
		st r5, 210
		st r5, 219
		st r5, 228
		live %131
		zjmp %:entry
                                                                                                                      ./gmange/corelol.s                                                                                  000644  032017  010202  00000000211 13046414175 015647  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name 		"laugh"
.comment	"aff, just kidding"

hello:
	sti		r1, %:alive, %1
	fork	%:alive
	add		r2, r3, r4

alive:
	live	%0
	zjmp	%:alive
                                                                                                                                                                                                                                                                                                                                                                                       ./gpetrov/MarineKing.s                                                                              000644  032017  010202  00000002537 13046414175 016501  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "MKP"
.comment "SaR ez Gg"

sti		r1, %:live, %1
st		r1, 6
live	%433
#sti		r1, %:relive, %1
ld		%1, r2
live	%45223
ld		%1, r3
live	%13123
sti		r1, %:wall, %1
ld		%0, r15

spawn:
	live	%45223
	fork	%:spawn2
	ld		%0, r15
	add		r2, r3, r2
	zjmp	%:wall

spawn2:
	live	%651
	fork	%:spawn3
	ld		%0, r15
	ld		%0, r15
	ld		%0, r15
	zjmp	%:spawn2


spawn3:
	live	%9814
	fork 	%:spawn

wall:
	live	%4902343
	st		r2, -24
	st		r2, -33
	st		r2, -42
	st		r2, -51
	st		r2, -60
	st		r2, -69
	st		r2, -78
	st		r2, -87
	st		r2, -96
	st		r2, -105
	st		r2, -114
	st		r2, -123
	st		r2, -132
	st		r2, -141
	st		r2, -150
	st		r2, -159
	st		r2, -168
	st		r2, -177
	st		r2, -186
	st		r2, -195
	st		r2, -204
	st		r2, -213
	st		r2, -222
	st		r2, -231
	st		r2, -240
	st		r2, -249
	st		r2, -258
	st		r2, -267
	st		r2, -276
	st		r2, -285
	st		r2, -294
	st		r2, -303
	st		r2, -312
	st		r2, -321
	st		r2, -330
	st		r2, -339
	st		r2, -348
	st		r2, -357
	st		r2, -366
	st		r2, -375
	st		r2, -384
	st		r2, -393
	st		r2, -402
	st		r2, -411
	st		r2, -420
	st		r2, -429
	st		r2, -438
	st		r2, -447
	st		r2, -456
	st		r2, -465
	st		r2, -474
	st		r2, -483
	st		r2, -492
	st		r2, -501
	st		r2, -510
	zjmp	%:wall

forks:
	live 	%651264
	add 	r2, r3, r2
	xor 	r2, %15, r4
	zjmp	%:forks

live:
	live %1
	zjmp %:live

relive:
	live %6514
	zjmp %:forks
	ld %0, r4
	zjmp %:relive

endwhile:
	live %9751364
	ld %0, r4
                                                                                                                                                                 ./gudepard/Kappa.s                                                                                  000644  032017  010202  00000011756 13046414175 015621  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Kappa.s                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/13 21:37:45 by gudepard          #+#    #+#              #
#    Updated: 2014/02/15 01:27:59 by gudepard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name				"Kappa"
.comment			"AKA Kappa Sandwich."

	# st	r2,	15
	# st	r3,	-1
	# live	%1							  |      r1       |
	# 0370 0200		0f03 7003		ffff 01xx		xxxx xx
	# 57672192		251883523		4294902016		xx

	# p1 -> r2 : 57672192
	#	 -> r3 : 19 st r3 -> 1303 7003 -> 318992387

	# p2 -> r2 : 251883523
	# 	 -> r3 : 23 st r3 -> 1703 7003 -> 386101251

	# p3 -> r2 : 4294902016
	#	 -> r3 : 26 st r3 -> 1A03 7003 -> 436432899

	# p4 -> r2 : r1
	#	 -> r3 : 15 st r3 -> 0f03 7003 -> 251883523

	#### REVERSE
	# st	r2,	-18
	# st	r3,	-1
	# live	%1							  -7			   -3
	# zjmp	%-15						  |      r1        |
	# 0370 02ff		ee03 7003		ffff 01xx		xxxx xx	09ffdf[03]
	# 57672447		3993202691		4294902016		xx		167763715

	# p1 -> r2 : 57672447
	#	 -> r3 : -14 st r3 -> f203 7003 -> 4060311555

	# p2 -> r2 : 3993202691
	#	 -> r3 : -10 st r3 -> f603 7003 -> 4127420419

	# p3 -> r2 : 4294902016
	#	 -> r3 : -7 st r3 -> f903 7003 -> 4177752067

	# p4 -> r2 : r1
	#	 -> r3 : -3 st r3 -> fd03 7003 -> 4244860931

	# p5 -> r2 : 167763715
	#	 -> r3 : -18 st r3 -> ee03 7003 -> 3993202691

	# 0000 0370		02ff ee03	7003 ffff	0100 0000	0109 ffdf
	# 880			50327043	1879310335	16777216	17432543

		sti		r1,		%:alive,		%1
		ld		%75,	r13
		aff		r13
		fork	%:init_forward
		live	%1337

init_backward:
		ld		%880,			r5		# 7
		ld		%50327043,		r6		# 7
		ld		%1879310335,	r7		# 7
		ld		%16777216,		r8		# 7
		ld		%17432543,		r9		# 7
		st		r5,				-80		# 5
		st		r6,				-81		# 5
		st		r7,				-82		# 5
		st		r8,				-83		# 5
		st		r9,				-84		# 5
		fork	%:r_p5					# 3
		live	%42						# 5
		fork	%:r_p4					# 3
		live	%42						# 5
		fork	%:r_p3					# 3
		live	%42						# 5
		fork	%:r_p2					# 3
		live	%42						# 5
		fork	%:r_p1					# 3
		ld		%0,				r2		# 7 carry = 1
		zjmp	%:init_forward			# 3

r_p1:
		ld		%57672447,		r2		# 7
		ld		%4060311555,	r3		# 7
		ld		%0,				r4		# 7
r_p1_2:
		live	%42						# 5
		fork	%:r_p1_2				# 3
		zjmp	%-177					# 3

r_p2:
		live	%42						# 5
		ld		%3993202691,	r2		# 7
		ld		%4127420419,	r3		# 7
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
r_p2_2:
		live	%42						# 5
		fork	%:r_p2_2				# 3
		zjmp	%-222					# 3

r_p3:
		live	%42						# 5
		ld		%4294902016,	r2		# 7
		ld		%4177752067,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p3_2:
		live	%42						# 5
		fork	%:r_p3_2				# 3
		zjmp	%-280					# 3

r_p4:
		live	%42						# 5
		st		r1,				r2		# 7
		ld		%4244860931,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p4_2:
		live	%42						# 5
		fork	%:r_p4_2				# 3
		zjmp	%-348					# 3

r_p5:
		live	%42						# 5
		ld		%167763715,		r2		# 7
		ld		%3993202691,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p5_2:
		live	%42						# 5
		fork	%:r_p5_2				# 3
		zjmp	%-432					# 3

init_forward:
		live	%42
		fork	%:p4
		live	%42
		fork	%:p3
		live	%42
		fork	%:p2
		live	%42
		fork	%:p1
		ld		%0,				r2	# carry = 1

alive:
		live	%42
		zjmp	%:alive

p1:
		ld		%57672192,		r2
		ld		%318992387,		r3
		ld		%0,				r4	# carry = 1
p1_2:
		live	%42
		fork	%:p1_2
		zjmp	%:move_forward

p2:
		live	%42
		ld		%251883523,		r2
		ld		%386101251,		r3
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
p2_2:
		live	%42
		fork	%:p2_2
		zjmp	%:move_forward

p3:
		live	%42
		ld		%4294902016,	r2
		ld		%436432899,		r3
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
		live	%42
		fork	%:alive
p3_2:
		live	%42
		fork	%:p3_2
		zjmp	%:move_forward

p4:
		live	%42
		st		r1,				r2
		ld		%251883523,		r3
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
		live	%42
		fork	%:alive
		live	%42
		fork	%:alive
p4_2:
		live	%42
		fork	%:p4_2
		zjmp	%:move_forward

move_forward:
		st		r2,				15
		st		r3,				-1
		live	%1337
                  ./hmichals/Wall.s                                                                                   000644  032017  010202  00000002477 13046414175 015461  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         	.name "Wall"
	.comment "Werror(you) Wextra(me)"

start:
	ld		%1, r14
	zjmp	%:wallstart
	st		r15, -8				#	15
	
stlive:
	sti	    r1,	%:wall,	%1		#	7
	sti		r1, %:alive, %1
	sti		r1, %:forklive, %1
	sti		r1, %:wallstart, %1
	sti		r1, %:fork, %1
	sti     r1, %:fork, %9
	sti     r1, %:kta, %1
	sti     r1, %:kta, %9
	sti     r1, %:kta, %17		#	63
								#	78
fork:
	live	%66
	fork	%:wallstart
	live	%66
	fork	%:fork				#	16
								#	94
kta:
	live	%2576980377			#	99
	lfork	%925
	live    %66					#	107
	lfork   %1941
	live    %66					#	115
	lfork   %2957
	
forklive:	
	live	%66
	fork	%:forklive
	aff		r1

alive:
	live	%66
	ld		%0, r16
	zjmp	%:alive

wallstart:
	live	%66
    ld      %42991616, r2
	ld      %265, r3
	ld      %4294508544, r4
	fork	%:wallstart

wall:
	live    %66
	st      r2, -300
	st      r3, -301
	st      r4, -302
	st      r2, -303
	st      r3, -304
	st      r4, -305
	st      r2, -306
	st      r3, -307
	st      r4, -308
	st      r2, -309
	st      r3, -310
	st      r4, -311
	st      r2, -312
	st      r3, -313
	st      r4, -314
    st      r2, -315
	st      r3, -316
	st      r4, -317
	st      r2, -318
	st      r3, -319
	st      r4, -320
	st      r2, -321
	st      r3, -322
	st      r4, -323
	st      r2, -324
	st      r3, -325
	st      r4, -326
	st      r2, -327
	st      r3, -328
	st      r4, -329
	ld		%0, r16
	zjmp	%:wall
                                                                                                                                                                                                 ./hmoutaou/Misaka_Mikoto.s                                                                          000644  032017  010202  00000007053 13046414175 017355  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name		"Misaka Mikoto"
.comment	"Misaka Mikoto (御坂 美琴 Misaka Mikoto) (born May 2) is a main heroine in Toaru Majutsu no Index and the main protagonist of Toaru Kagaku no Railgun. Introduced in the first volume of the light novels, her role in the story was later expanded in the third volume as well as the release of the Toaru Kagaku no Railgun manga, making her the main heroine of the science side and the second main heroine of the series.

	She is the third ranked Level 5 esper in Academy City, and is nicknamed the Railgun due to her signature move. Kamijou Touma coined the nickname Biri-Biri (ビリビリ?) (a Japanese onomatopoeia imitating the sound of electricity) for her and whenever the two meet he usually calls her that, even after his amnesia"

entry:
	sti		r1, %:run, %1			; live :run
	sti		r1, %:f1_a, %1			; live :f2_a
	sti     r1, %:f1_b, %1			; live :f2_b
	sti     r1, %:f2_a, %1			; live :f2_c
	sti     r1, %:f2_d, %1			; live :f2_d

	st      r2, :entry			; clear entry + 0

nothing:
	fork	%:clear
	add		r3, r3, r3
	zjmp	%:loader

filler:
	zjmp	%:run
	zjmp    %:run
	zjmp    %:run
	zjmp    %:run
	zjmp    %:run
	zjmp    %:run

clear:
	live	%404
	
	add		r3, r3, r3
	fork	%:f0_z
	zjmp	%:f1_a

f0_z:
	zjmp	%:f1_b

f1_a:
	live	%404
	fork	%:f1_z
	zjmp	%:f2_a

f1_b:
	live	%404
	fork	%:f1_y
	zjmp	%:f2_b

f1_z:
	zjmp	%:f2_c

f1_y:
	zjmp	%:f2_d



f2_a:
	live    %404
	fork	%:f2_z
	zjmp	%:f3_a
f2_b:
	live    %404
	fork    %:f2_y
	zjmp    %:f3_b
f2_c:
	live    %404
	fork    %:f2_w
	zjmp    %:f3_c
f2_d:
	live    %404
	fork    %:f2_x
	zjmp    %:f3_d
f2_z:
	zjmp	%:f3_e
f2_y:
	zjmp    %:f3_f
f2_x:
	zjmp    %:f3_g
f2_w:
	zjmp    %:f3_h



f3_b:							;snipe run + 12
	ld		%-498, r9
	ldi     %0, %:bomb_b, r8
	add     r3, r3, r3
	zjmp	%:run

f3_f:							;snipe before + 4
	ld		%-504, r9
	ldi     %0, %:bomb_b, r8
	add     r3, r3, r3
	zjmp	%:run

f3_d:							;snipe after - 8
	ld		%508, r9
	ldi     %0, %:bomb_a, r8
	add     r3, r3, r3
	zjmp	%:run

f3_c:							;snipe after
	ld		%516, r9
	ldi     %0, %:bomb_a, r8
	add     r3, r3, r3
	zjmp	%:run

f3_g:							;snipe after - 4
	ld		%512, r9
	ldi     %0, %:bomb_a, r8
	add     r3, r3, r3
	zjmp	%:run

f3_a:							;run + 8
	ld		%19, r9
	ldi     %8, %:run, r8
	add     r3, r3, r3
	zjmp	%:run

f3_e:							;run + 0
	ld		%11, r9
	ldi     %0, %:run, r8
	add     r3, r3, r3
	zjmp	%:run

f3_h:							;run + 4
	ld		%15, r9
	ldi     %4, %:run, r8
	add     r3, r3, r3
	zjmp	%:run

run:
	live	%777
	sti		r8, %:run, r9
	sti     r8, %:run, r9
	sti     r8, %:run, r9
	sti     r8, %:run, r9
	sti     r8, %:run, r9
	sti     r8, %:run, r9
	sti     r8, %:run, r9
	sti     r8, %:run, r9

bomb_b:
	lfork	%-50

bomb_a:
	zjmp	%0

data_miner:
	live	%404
	
loader:
	ldi		%0,	%:data_miner, r3
	
shotgun:
	ldi		%7, %:shotgun, r2
	st		r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	st      r2, 256
	live	%404
	st		r3, 256
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ./kelickel/Varimathras.s                                                                            000644  032017  010202  00000001555 13046414175 017032  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name		"Varimathras"
.comment	"If I have wings, why am I always walking?"

piege:
	st		r1, r9 #/ ld nous, r9
	live	%0
	ld		%656, r1
	ld		%151162880, r2
	sti		r1, %:piege, %0
	sti		r9, %:piege, %4
	sti		r2, %:piege, %8

init_buldog:
	ld		%0, r1
	ld		%4, r3
	ld		%88, r4
	sti		r9, %:buldog, %1
	sti		r9, %:live1, %1
	sti		r9, %:live2, %1
	sti		r9, %:live3, %1

buldog:
	live	%0
	ldi		%:buldog, r1, r2
live1:
	live	%0
	sti		r2, %:fin, r1
live2:
	live	%0
	add		r1, r3, r1
	xor		r1, r4, r16
	zjmp	%:suite
live3:
	live	%0
	and		%0, %0, r16
	zjmp	%:buldog
suite:
	ld		%0, r1
	and		%0, %0, r16
	zjmp	%:fin

complicate:
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
fin:
                                                                                                                                                   ./kmonrose/justin_bee.s                                                                             000644  032017  010202  00000003323 13046414175 016745  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "L'arene des abeilles"
.comment "Baby, baby, baby, oh !"

ertuen:
	sti		r1, %:label1, %1
	sti		r1, %:label2, %1
	sti		r1, %:label3, %1
	sti		r1, %:label4, %1
	sti		r1, %:label5, %1
	sti		r1, %:label6, %1
	sti		r1, %:label7, %1
	sti		r1, %:label8, %1
	sti		r1, %:label9, %1
	ld		%0, r16
	fork	%:label1

label4:
	live	%314
	ld		%31415926, r2
	ld		%0, r16
	fork	%:label3

label6:
	live	%314
	ld		%0, r16
	fork	%:label5

label7:
	ld		%62821932, r5
	ld		%0, r16
	fork	%:label8
	
label2:
	live	%314
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st      r2, -450
	st      r2, -450
	zjmp	%:label2

label1:
	live	%314
	zjmp	%:label1

label3:
	live	%314
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st      r2, 450
	st      r2, 450
	zjmp	%:label3
	
label5:
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	zjmp	%:label6

label8:
	zjmp	%:label9
	st		r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500

label9:
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
                                                                                                                                                                                                                                                                                                             ./ldesgoui/_honeybadger.s                                                                           000644  032017  010202  00000005603 13046414175 017225  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "HoneyBadger"
.comment "This is where I'd put the forks. IF I HAD ANY"

ld %0, r2
zjmp %:var2
var1:
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
var2:
zjmp %:var225
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
lfork %:var1
var225:
ld %57672449, r4
ld %4278780410, r5
ld %151087104, r3
ld %0, r2
st r4, 511
st r5, 510
zjmp %501
                                                                                                                             ./lseguin/skynet.s                                                                                  000644  032017  010202  00000003436 13046414175 015751  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "skynet"
.comment "j'aime les chats"

setlive:
	st r1, 7
	ld %323, r1
	ld %0, r2
	st r2, :setlive
	sti r2, %:setlive, %1
	sti r1, %:wall, %1
	sti r1, %:wall, %1
	sti r1, %:wall2, %1
	sti r1, %:live, %1
	sti r1, %:live1, %1
	sti r1, %:loop, %1

wall_prep:
	ld		%0, r2
	ld		%0, r16

fork %:wall

live1:
	live	%12345

fork %:wall2
zjmp %:loop

wall:
	live	%12345
	st	r2, -37
	st	r2, -46
	st	r2, -55
	st	r2, -64
	st	r2, -73
	st	r2, -82
	st	r2, -91
	st	r2, -100
	st	r2, -109
	st	r2, -118
	st	r2, -127
	st	r2, -136
	st	r2, -145
	st	r2, -154
	st	r2, -163
	st	r2, -172
	st	r2, -181
	st	r2, -190
	st	r2, -199
	st	r2, -208
	st	r2, -217
	st	r2, -226
	st	r2, -235
	st	r2, -244
	st	r2, -253
	st	r2, -262
	st	r2, -271
	st	r2, -280
	st	r2, -289
	st	r2, -298
	st	r2, -307
	st	r2, -316
	st	r2, -325
	st	r2, -334
	st	r2, -343
	st	r2, -352
	st	r2, -361
	st	r2, -370
	st	r2, -379
	st	r2, -388
	st	r2, -397
	st	r2, -406
	st	r2, -415
	st	r2, -424
	st	r2, -433
	st	r2, -442
	st	r2, -451
	st	r2, -460
	st	r2, -469
	st	r2, -478
	st	r2, -487
	st	r2, -496
	st	r2, -505
	st	r2, -511
	zjmp %:wall

loop:
	live %12345
	fork %:live
zjmp %:loop

live:
	live %12345
zjmp %:live

wall2:
	live %12345
	st	r2, 273
	st	r2, 272
	st	r2, 271
	st	r2, 270
	st	r2, 269
	st	r2, 268
	st	r2, 267
	st	r2, 266
	st	r2, 265
	st	r2, 264
	st	r2, 263
	st	r2, 262
	st	r2, 261
	st	r2, 260
	st	r2, 259
	st	r2, 258
	st	r2, 257
	st	r2, 256
	st	r2, 255
	st	r2, 254
	st	r2, 253
	st	r2, 252
	st	r2, 251
	st	r2, 250
	st	r2, 249
	st	r2, 248
	st	r2, 247
	st	r2, 246
	st	r2, 245
	st	r2, 244
	st	r2, 243
	st	r2, 242
	st	r2, 241
	st	r2, 240
	st	r2, 239
	st	r2, 238
	st	r2, 237
	st	r2, 236
	st	r2, 235
	st	r2, 234
	st	r2, 233
	st	r2, 232
	st	r2, 231
	st	r2, 230
	st	r2, 229
	st	r2, 228
	st	r2, 227
	st	r2, 226
	st	r2, 225
	st	r2, 223
	st	r2, 222
	st	r2, 221
	st	r2, 220
	zjmp %:wall2
                                                                                                                                                                                                                                  ./lsirigna/live.s                                                                                   000644  032017  010202  00000003265 13046414175 015535  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name		"zdoh"
.comment	"w8 for da next one"

lol:	sti		r3, -1, %1
	and		r3, %0, r3

jmp:	fork		%:start
ld		0, r4
st		r4, -6
zjmp		%:jmp

start:	live		%0
live		%42
fork		%:live
fork		%:live
fork		%:live
fork		%:live
fork		%:live
fork		%:live
fork		%:live
fork		%:live
fork		%:live
fork		%:live
fork		%:start
fork		%:start
fork		%:live
fork		%:start
fork		%42
fork		%42
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:wall
fork		%:start

live:
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
live	%1
fork	%:wall
fork	%:live

wall:	live	%42
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-500
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
st      r8,-400
zjmp	%:wall
                                                                                                                                                                                                                                                                                                                                           ./mbacoux/meowluigi.s                                                                               000644  032017  010202  00000003374 13046414175 016426  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "Meow Luigi"
.comment "Here we meoooooow !"

shield2:
	zjmp	%:shield2

start:
	ld		%0, r16
	sti		r1, %:mloop, %1
	fork	%:protect

mloop:
	live	%0
	fork	%:main
	zjmp	%:mloop

proloop:
	live	%0
	st		r15, -200
	st		r15, -201
	st		r15, -202
	st		r15, -203
	st		r15, -204
	st		r15, -205
	st		r15, -206
	st		r15, -207

proloop_2:
	live	%0
	st		r15, -213
	st		r15, -214
	st		r15, -215
	st		r15, -216
	st		r15, -217
	zjmp	%:proloop

protect2:
	live	%0
	fork	%:proloop
	zjmp	%:protect2

protect:
	live	%0
	fork	%:protect2
	zjmp	%:protect

main:
	sti		r1, %:replicate, %1
	sti		r1, %:mloop, %1
	sti		r1, %:main2, %1
	sti		r1, %:main3, %1
	sti		r1, %:main4, %1
	sti		r1, %:replicate_loop, %1
	sti		r1, %:protect, %1
	sti		r1, %:protect2, %1
	sti		r1, %:proloop, %1
	sti		r1, %:proloop_2, %1
	sti		r1, %:loop, %1
	sti		r1, %:loop, %6
	sti		r1, %:loop, %11
	sti		r1, %:loop, %16
	sti		r1, %:loop, %21
	sti		r1, %:loop, %26
	sti		r1, %:loop, %31
	sti		r1, %:loop, %36
	sti		r1, %:loop, %41
	sti		r1, %:loop, %46
	sti		r1, %:loop, %51
	sti		r1, %:loop, %56
	sti		r1, %:loop, %61
	sti		r1, %:loop, %66
	sti		r1, %:loop, %71
	sti		r1, %:loop, %76
	fork	%:protect

main2:
	live	%0
	fork	%:replicate

main3:
	live	%0
	fork	%:main4
	zjmp	%:main3

main4:
	live	%0
	fork	%:loop
	zjmp	%:main4

loop:
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	zjmp	%:loop

replicate:
	live	%0
	ld		%0, r4
	ld		%8, r5
	ld		%4, r6
	ld		%220, r8
	fork	%:replicate_loop
	ld		%4, r4

replicate_loop:
	live	%0
	ldi		%:main2, r4, r2
	sti		r2, %:replicated, r4
	add		r4, r5, r4
	sub		r4, r8, r16
	zjmp	%:replicated
	sub		r16, r6, r16
	zjmp	%:replicated
	ld		%0, r16
	zjmp	%:replicate_loop

replicated:
	live	%0

                                                                                                                                                                                                                                                                    ./mconraux/dubo.s                                                                                   000644  032017  010202  00000000310 13046414175 015537  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "dubo"
.comment "Tu veux du pain"

pede:
live %1
live %1
live %1
live %1
live %1
live %1
live %1
zjmp %:pede

nodeadplz:
	live %1
	live %1
	live %1
	live %3
	live %2
	live %2
	zjmp %:nodeadplz

                                                                                                                                                                                                                                                                                                                        ./rabid-on/jinx.s                                                                                   000644  032017  010202  00000002210 13046414175 015416  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "Jinx"
.comment "Stay still, I'm trying to shoot you..!"

init:
	st		r1, :replic1
	st		r6, -4
	ld		:replic1, r1

start1:
	ld		%0, r7
	zjmp	%:start2

stuff1:
	live	%66
	ldi		%-5, r3, r1
	sti		r1, %-173, r3
	add		r3, r4, r3
	xor		r5, r3, r6
	zjmp	%:stuff2

stuff2:
	xor		r3, r3, r3
	zjmp	%-207

replic1:
	st		r1, r1

start2:
	sti		r1, %:live0, %1

live0:
	live	%66
	sti		r2, %:start1, %-60
	ld		%4, r4
	st		r2, 512

replic2:
	ld		%48, r5
	sti		r1, %:stuff1, %1
	sti		r1, %:stuff3, %1
	sti		r1, %:live1, %1
	sti		r1, %:live2, %1
	sti		r1, %:live3, %1
	sti		r1, %:live4, %1
	sti		r1, %:live5, %1

live1:
	live	%66

live2:
	live	%66

live3:
	live	%66

live4:
	live	%66

live5:
	live	%66
	zjmp	%:live1
	xor		r3, r3, r3
	sti		r1, %:live6, %1

live6:
	live	%66
	fork	%:live1
	sti		r1, %:loop, %1
	sti		r1, %:loop, %9
	sti		r1, %:loop, %17
	sti		r1, %:loop, %25

loop:
	live	%66
	fork	%:stuff1
	live	%66
	fork	%:loop
	live	%66
	fork	%:stuff3
	live	%66
	zjmp	%:stuff1

stuff3:
	live	%66
	ldi		%-5, r3, r1
	sti		r1, %147, r3
	add		r3, r4, r3
	xor		r5, r3, r3
	zjmp	%:stuff4
	ld		%0, r7
	zjmp	%:stuff4
	ld		%0, r7
	zjmp	%:stuff3

stuff4:
	xor		r3, r3, r3
	zjmp	%113
                                                                                                                                                                                                                                                                                                                                                                                        ./rmasse/THUNDER.s                                                                                  000644  032017  010202  00000003421 13046414175 015363  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "thunder"
.comment "you've been thunderstruck..."

main:
	sti			r1, %:start, %1
	sti			r1, %:back, %1
	sti			r1, %:front, %1
	sti			r1, %:live, %1
	ld			%0, r16
	fork		%:start

live:
	live		%42
	ld			%0, r2
	ld			%0, r16
	fork		%:front

back:
	live		%42
	st		r2, -24
	st		r2, -33
	st		r2, -42
	st		r2, -51
	st		r2, -60
	st		r2, -69
	st		r2, -78
	st		r2, -87
	st		r2, -96
	st		r2, -105
	st		r2, -114
	st		r2, -123
	st		r2, -132
	st		r2, -141
	st		r2, -150
	st		r2, -159
	st		r2, -168
	st		r2, -177
	st		r2, -186
	st		r2, -195
	st		r2, -204
	st		r2, -213
	st		r2, -222
	st		r2, -231
	st		r2, -240
	st		r2, -249
	st		r2, -258
	st		r2, -267
	st		r2, -276
	st		r2, -285
	st		r2, -294
	st		r2, -303
	st		r2, -312
	st		r2, -321
	st		r2, -330
	st		r2, -339
	st		r2, -348
	st		r2, -357
	st		r2, -366
	st		r2, -375
	st		r2, -384
	st		r2, -393
	st		r2, -402
	st		r2, -411
	st		r2, -420
	st		r2, -429
	st		r2, -438
	st		r2, -447
	st		r2, -456
	st		r2, -465
	st		r2, -474
	st		r2, -483
	st		r2, -492
	st		r2, -501
	st		r2, -510
	zjmp		%:back

start:
	live		%42
	zjmp		%:start

front:
	live		%42
	st		r2, 24
	st		r2, 33
	st		r2, 42
	st		r2, 51
	st		r2, 60
	st		r2, 69
	st		r2, 78
	st		r2, 87
	st		r2, 96
	st		r2, 105
	st		r2, 114
	st		r2, 123
	st		r2, 132
	st		r2, 141
	st		r2, 150
	st		r2, 159
	st		r2, 168
	st		r2, 177
	st		r2, 186
	st		r2, 195
	st		r2, 204
	st		r2, 213
	st		r2, 222
	st		r2, 231
	st		r2, 240
	st		r2, 249
	st		r2, 258
	st		r2, 267
	st		r2, 276
	st		r2, 285
	st		r2, 294
	st		r2, 303
	st		r2, 312
	st		r2, 321
	st		r2, 330
	st		r2, 339
	st		r2, 348
	st		r2, 357
	st		r2, 366
	st		r2, 375
	st		r2, 384
	st		r2, 393
	st		r2, 402
	st		r2, 411
	st		r2, 420
	st		r2, 429
	st		r2, 438
	st		r2, 447
	st		r2, 456
	st		r2, 465
	st		r2, 474
	st		r2, 483
	st		r2, 492
	st		r2, 501
	st		r2, 510
	zjmp		%:front
                                                                                                                                                                                                                                               ./sbuono/Asombra.s                                                                                  000644  032017  010202  00000004011 13046414175 015645  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "King Sombra"
.comment "Crystal empire is mine!"

init:
rest:
fork %:go
live %0
fork %:go2
prelive:
ld %251658255, r2
ld %1, r12
ld %40, r11
st r1, 11
st r16, -4
shield:
live %0
st r16, -300
st r2, -301
st r2, -302
sub r11, r12, r11
zjmp %:fork
ld %0, r16
zjmp %:shield

go:
ld %0, r16
zjmp %:assaut1

go2:
ld %0, r16
zjmp %:assaut2

fork:
ldi %:shield, %1, r13
ld %0, r16
st r13, 6
forkcycle:
live %0
fork %:forkcycle

eraser:
st r13, 6
live %0
fork %:part2

part1:
ld %190056971, r10 # sti r10,r11
ld %135004416, r7 # r8,r12 live
ld %273, r8
ld %270, r11
ld %0, r12
fork %:start1
zjmp %:start2

part2:
ld %202068999, r10 # r12 sti r7
st r13, r7
ld %276, r8
ld %274, r11
ld %0, r12
fork %:start1
zjmp %:start2

start1:
zjmp %3
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
start2:
sti r10, r11, r12
sti r7, r8, r12
live %0

assaut2:
live %0
ld %190055943, r10 # sti r6, r7
ld %84476405, r11 # r5 jump 01F5 (501)
ld %150994956, r3 #0x0900000c
ld %150994956, r6 #0x0900000c
ld %26, r7
ld %495, r4
ld %0, r5
zjmp %:jump

assaut1:
live %0
ld %190055943, r10 # sti r6, r7
ld %84476405, r11 # r5 jump 01F5 (501)
fork %:second
ld %190055172, r3 #0x0B540304
ld %190055172, r6 #0x0B540304
ld %507, r7
ld %24, r4
ld %0, r5
zjmp %:jump

second:
live %0
ld %84475923, r3 #0x0509001b
ld %84475923, r6
ld %511, r7
ld %28, r4
ld %0, r5
zjmp %:jump

jump:
live %0
st r10, 511
st r11, 510
zjmp %501
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ./srabah-m/littlepuppy.s                                                                            000644  032017  010202  00000001460 13046414175 017046  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "Little Puppy"
.comment "Wang Wang!!!!"

ld		%0, r3
live	%42
sti		r15, %0, r14
live	%42
sti		r15, %0, r14
live	%42
sti		r15, %0, r14
live	%42
sti		r15, %0, r14
sti     r15, %0, r14
sti     r15, %0, r14
sti     r1, %65462, %1
sti     r1, %65455, %15
sti     r1, %65448, %29
sti     r1, %65441, %43
sti     r1, %65434, %57
sti     r1, %65427, %71
ld      %393216, r4
ld      %917504, r12
ld      %1, r11
ld      %6, r10
live    %42
sti     r4, %65381, %1
add     r4, r12, r4
sub     r10, r11, r10
live    %3
live    %4
live    %42
ldi     %8, %65343, r15
ld      %-186, r14
ld      %0, r2
live    %42
live    %42
ldi     %4, %65306, r15
ld      %-190, r14
ld      %0, r2
live    %42
ldi     %12, %65277, r15
ld      %-182, r14
ld      %0, r2
live    %42
ldi     %0, %65248, r15
ld      %-194, r14
ld      %0, r2
                                                                                                                                                                                                                ./tdemay/champ.s                                                                                    000644  032017  010202  00000004762 13046414175 015344  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         ;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    champ.s                                            :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: aelola <aelola@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2014/02/25 11:56:47 by aelola            #+#    #+#              ;
;    Updated: 2014/02/25 11:56:48 by aelola           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

.name		"lazer"
.comment	"Mundo dit beaucoup son nom pour pas l'oublier, pck c deja arriver!"

entry:
	sti		r1, %:live, %1
	sti		r1, %:mov, %1
	sti		r1, %:wall, %1
	sti		r1, %:torpille_front, %1
	sti		r1, %:write_front, %1
	and		r1, %0, r1
	ld		%100, r4
	fork	%:wall
	zjmp	%:mov

live:
	live	%1566
	fork	%:write_front
	lfork	%:mov
	zjmp	%:live

init_write:
	ld		%0, r8
	ld		%5, r15

write_front:
af:
	live	%2
	ldi		%:init_write, r8, r16
	sti		r16, %:up, r8
	add		r15, r8, r8
	sti		r16, %:up, r8
bf:
	live	%3
	xor		r8, r3, r9
	zjmp	%:init_write
cf:
	ld		%0, r9
	zjmp	%:write_front

wall:
	live	%42
	ld		%1111638594, r2
	st		r2, -69
	st		r2, -74
	st		r2, -83
	st		r2, -92
	st		r2, -101
	st		r2, -109
	st		r2, -115
	st		r2, -123
	st		r2, -132
	st		r2, -141
	st		r2, -150
	st		r2, -159
	st		r2, -168
	st		r2, -177
	st		r2, -186
	st		r2, -195
	st		r2, -204
	st		r2, -213
	st		r2, -222
	st		r2, -231
	st		r2, -240
	st		r2, -249
	st		r2, -258
	st		r2, -267
	st		r2, -276
	st		r2, -285
	st		r2, -294
	st		r2, -303
	st		r2, -312
	st		r2, -321
	st		r2, -330
	st		r2, -339
	st		r2, -348
	st		r2, -357
	st		r2, -366
	st		r2, -375
	st		r2, -384
	st		r2, -393
	st		r2, -402
	st		r2, -411
	st		r2, -420
	st		r2, -429
	st		r2, -438
	st		r2, -447
	st		r2, -456
	st		r2, -465
	st		r2, -474
	st		r2, -483
	st		r2, -492
	st		r2, -501
	st		r2, -510
	zjmp	%:wall

mov_init:
	ld		%4, r8
	ld		%0, r4
	ld		%1111638594, r6
	# zjmp	%:mov_init

mov:
	live	%99
	sti		r6, :up, r4
	add		r4, r8, r4
	sti		r6, :up, r4
	add		r4, r8, r4
	fork	%:mov
	zjmp	%:mov

torpille_front:
	live	%4242
	add		r4, r8, r4
	sti		r6, r4, %:up
	add		r4, r8, r4
	sti		r6, r4, %:up
	zjmp	%:torpille_front

up:
              ./vrey/darksasuke.s                                                                                 000644  032017  010202  00000001507 13046414175 016105  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "Xx_DaRk_SaSuKe_93_xX"
.comment "The Dirty Hamster"

	st		r1, 235
	st		r1, 205
	ld		%8, r15
	ld		%1, r16
	ld		%-400, r13
	ld		%0, r11
	ld		%0, r16
	zjmp	%:start

lf:
	live	%9999999
	lfork	%:lf

start:
	ld		-3, r9
	ld		-13, r7
	ld		-17, r8
	ld		%300, r10
	fork	%:forward
	live	%999999
	fork	%:backward
	ld		%0, r16
	zjmp	%:initlive

initlive:
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	ld		%0, r16

live:
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	zjmp	%:live

backward:
	live	%9999999
	sub		r13, r15, r13
	sti		r9, r10, r13
	ld		%0, r16
	zjmp	%:backward

forward:
	live	%9999999
	add		r11, r15, r11
	sti		r7, r10, r11
	sti		r8, r10, r11
	ld		%0, r16
	zjmp	%:forward

                                                                                                                                                                                         ./ybouvet/casimir.s                                                                                 000644  032017  010202  00000001542 13046414175 016106  0                                                                                                    ustar 00dmoureu-                        2015_paris                      000000  000000                                                                                                                                                                         .name "CASIMIR"
.comment "GLOUBIBOULGA"

	ld %880, r2
	ld %16778753, r3
	ld %4, r4
	ld %72618000, r5
	ld %269090801, r6
	st r1, 6
	live %456
	fork %:live
	add r16, r16, r16
	zjmp %:forknikator
live:
	st r1, 6
	live %546
	st r2, 1023
	st r3, 1022
	st r4, 1021
	st r5, 1020
	st r6, 1019
	fork %993
	sti r1, %:live2, %1
	fork %:live2
	add r16, r16, r16
	zjmp %:live
live2:
	live %4
	add r16, r16, r16
	zjmp %:live2
forknikator:
	st r1, 6
	live %37
	fork %:protect1
	fork %:protect2
	add r16, r16, r16
	zjmp %:forknikator
protect1:
	st r1, 6
	live %789
	st r2, -129
	st r3, -130
	st r4, -131
	st r5, -132
	st r6, -133
	st r16, -134
	st r16, -135
	st r16, -136
	add r16, r16, r16
	zjmp %:protect1
protect2:
	st r1, 6
	live %212
	st r2, -219
	st r3, -220
	st r4, -221
	st r5, -222
	st r6, -223
	st r16, -224
	st r16, -225
	st r16, -226
	add r16, r16, r16
	zjmp %:protect2
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              