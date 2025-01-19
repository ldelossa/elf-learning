.text
b start

arr: .byte 10, 20, 25
eoa:

.align
start:
	ldr		r0, =arr
	ldr		r1, =eoa

	bl		sum

stop: b stop
