.name       "Batman"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1		# comment
live:
		live %0
		st r6,-4
		zjmp %:typing
		sti     r1,%:copie,%2
		ld %0, r2
label1:
	label: ld %18446744073709551615, r2
		sub	r2,r4,r2
		zjmp %:loop
		zjmp %:empty
		st r3, r5
		
ardefwrite:
ardefl1:
	live	%295423

sti		r1, %:ardefl1, %1

typing: aff r2		
typing: aff r2

copie:	ld  %1,r1
		xor	r10,r10,r10
empty:
