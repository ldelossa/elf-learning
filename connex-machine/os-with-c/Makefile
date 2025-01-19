
os.flash: os.bin
	rm -rf os.flash
	dd if=/dev/zero of=$@ bs=4096 count=4096
	dd if=$< of=$@ conv=notrunc

os.bin: os
	arm-none-eabi-objcopy -O binary $< $@

os: os.lds os.o int_vector.o sum.o
	arm-none-eabi-ld -T $< -o $@ os.o int_vector.o sum.o

%.o: %.s
	arm-none-eabi-as -o $@ $<

%.o: %.c
	arm-none-eabi-gcc -nostdlib -c $< -o $@

simple:
	arm-none-eabi-gcc -nostdlib -o os -T os.lds sum.c int_vector.s os.s

.PHONY:
clean:
	rm -rf os
	rm -rf *.o
	rm -rf *.bin
	rm -rf *.flash


