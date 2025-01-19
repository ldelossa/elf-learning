SECTIONS {
	. = 0x00000000;
	.text : { * (.text); }
	flash_data_start = .;

	. = 0xA0000000;
	ram_start = .;
	.data : AT (flash_data_start) { * (.data); }
	ram_end = .;
	data_size = ram_end - ram_start;
}
