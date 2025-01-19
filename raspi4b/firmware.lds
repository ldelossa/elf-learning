SECTIONS {
	. = 0x8000;
	.text : {
		* (text.firmware);
		* (.text);
	}
}
