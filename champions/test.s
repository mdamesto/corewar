.name "test_name"
.comment "test_comment"

entry:
	or 123, %12, r3
	live %:yo
	live %1234567
	ld :yo,r10
	lld 123, r10
	st r10, 123
	st r10, 123
	add r1, r2, r3
	st r10, 123
	sub r1, r2, r3
	and 123, r3
	or 123, %12, r3
	zjump %123
	fork %:yo
	lfork %123
	aff r14
yo:
	live %:entry
