.text
.global start
start:
	@ linker script provides LMA of RAM, VMA, and the end VMA, we will use these
	@ to copy static RAM bits into memory where we can read/write.
	ldr	r1, =ram_lma
	ldr r2, =ram_vma_start
	ldr r3, =ram_size

	@ handle the case where no RAM is used
	cmp r3, #0
	beq	init_bss
copy:
	ldrb	r4, [r1], #1
	strb	r4, [r2], #1
	subs	r3, r3, #1

	bne copy

init_bss:
	ldr		r1, =bss_start
	ldr		r2, =bss_end
	ldr		r3, =bss_size

	mov		r4, #0

init_bss_loop:
	strb	r4, [r1], #1
	subs	r3, r3, #1
	bne		init_bss_loop

init_stack:
	ldr		sp, =0xA4000000
	bl		main

idle:
	b idle
