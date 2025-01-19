SECTIONS {
	. = 0x00000000;
	.text : {
		 * (vectors);
		 * (.text);
	}
	/* RAM LMA will exist at address immediately after .text section */
	ram_lma = .;

	/* RAM VMA */
	. = 0xA0000000;
	ram_vma_start = .;
	/* tell linker to link .data sections at the RAM LMA.
	 * all references to symbols in .data will reference the VMA address at or
	 * at offset of 0xA0000000
	 */
	.data : AT (ram_lma) {
		* (.data);
	}
	ram_vma_end = .;
	ram_size = ram_vma_end - ram_vma_start;
}
