.name       "Batman"
.comment    "This city needs me"

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
