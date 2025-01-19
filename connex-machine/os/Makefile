
os.flash: os.bin
	rm -rf os.flash
	dd if=/dev/zero of=$@ bs=4096 count=4096
	dd if=$< of=$@ conv=notrunc

os.bin: os
	arm-none-eabi-objcopy -O binary $< $@

os: os.lds os.o int_vector.o
	arm-none-eabi-ld -T $< -o $@ os.o int_vector.o

%.o: %.s
	arm-none-eabi-as -o $@ $<

.PHONY:
clean:
	rm -rf os
	rm -rf *.o
	rm -rf *.bin
	rm -rf *.flash


