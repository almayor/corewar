.name       "Batman"
.comment    "This city needs me"
.extend								# new error case

loop:
        sti r1, %:live, %1		# comment
live
		live %0
		zjmp %:typing
		sti     r1,%:copie,%2
		ld %0, r2
		sub	r2,r4,r2
		zjmp %:loop
		st r3, r5


typing: aff r2		
	   
copie:	ld  %1,r1
		xor	r10,r10,r10


# new error cases

# st	r1, :l1+1
# live:	zjmp	%:l1 - 100
# .code	00 00 00
# ld %0x08F40370,r3

# check op readeing without splits: ld %0,r1 (instead of ld %0, r1)
