@ data will be our RAM, it will exist in the ROM directly after .text section
@ and be loaded from LMA to 0x50000000 where RAM exists.
.data
val1:	.4byte 10
val2:	.4byte 20
res: 	.byte   0

.text
.global start
start:
	@ linker script provides LMA of RAM, VMA, and the end VMA, we will use these
	@ to copy static RAM bits into memory where we can read/write.
	ldr	r1, =ram_lma
	ldr r2, =ram_vma_start
	ldr r3, =ram_size

copy:
	ldrb	r4, [r1], #1
	strb	r4, [r2], #1
	subs	r3, r3, #1

	bne copy

init:
	@ use VMA of RAM address to compute val1 + val2 and store the result
	@ at address pointed to by res label

	ldr r1, =val1
	ldr r2, =val2

	ldr r1, =val1
	ldr r1, [r1]
	ldr r2, [r2]
	add r4, r1, r2

	ldr r0, =res
	str r4, [r0]

idle:
	b idle
