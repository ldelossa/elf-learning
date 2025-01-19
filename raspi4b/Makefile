firmware.bin: firmware
	arm-none-eabi-objcopy -O binary $< $@

firmware: firmware.o
	arm-none-eabi-ld -T ./firmware.lds -o $@ $<

firmware.o: firmware.s
	arm-none-eabi-as -o $@ $<

.PHONY:
clean:
	rm -rf firmware
	rm -rf *.bin
	rm -rf *.o
