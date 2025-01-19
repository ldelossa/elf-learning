@ r0: start address of array
@ r1: end address of array
@ r3: sum off array

.global sum

sum:
	mov		r3, #0
loop:
	ldrb	r2, [r0], #1
	add		r3, r2, r3
	cmp		r0, r1
	bne		loop
	mov		pc, lr
