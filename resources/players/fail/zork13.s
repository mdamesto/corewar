.comment "I'M ALIIIIVE"
.name "zork"

l2:		sti r1, 55, %1
		and r1, %0, r1

 live:	live %1
		zjmp %:live
