@ interrupt vector table starts at 0x0 in memory and contains jumps to
.section "vectors"

reset:	b start	@ start symbol defined in os.s
intr_undef:	b undef
intr_swi:	b swi
intr_pabrt:	b pabrt
intr_dabrt:	b dabrt
intr_irq:	b irq
intr_fiq:	b fiq

.text

undef:
	@ load register 00 with 0xA and reset
	ldr r0, =0xA
	b start

swi:
	@ load register 00 with 0xB and reset
	ldr r0, =0xB
	b start

pabrt:
	@ load register 00 with 0xC and reset
	ldr r0, =0xC
	b start

dabrt:
	@ load register 00 with 0xD and reset
	ldr r0, =0xD
	b start

irq:
	@ load register 00 with 0xE and reset
	ldr r0, =0xE
	b start

fiq:
	@ load register 00 with 0xF and reset
	ldr r0, =0xF
	b start

