#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>

int print_shdr(const char *const fname, size_t size) {
    int fd = open(fname, O_RDONLY);
    char *p = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);

	Elf64_Ehdr *ehdr = (Elf64_Ehdr *)p;
	Elf64_Shdr *sht = (Elf64_Shdr *)&p[ehdr->e_shoff];
	char *shstrtab = &p[sht[ehdr->e_shstrndx].sh_offset];

	for (int i = 0; i < ehdr->e_shnum; ++i) {

		// sh_name
		printf("[%d] %s\n\t", i, &shstrtab[sht[i].sh_name]);

		// sh_type
		switch(sht[i].sh_type) {
			case SHT_NULL: printf("NULL\n"); break;
			case SHT_PROGBITS: printf("PROGBITS\n"); break;
			case SHT_SYMTAB: printf("SYMTAB\n"); break;
			case SHT_STRTAB: printf("STRTAB\n"); break;
			case SHT_RELA: printf("RELA\n"); break;
			case SHT_HASH: printf("HASH\n"); break;
			case SHT_DYNAMIC: printf("DYNAMIC\n"); break;
			case SHT_NOTE: printf("NOTE\n"); break;
			case SHT_NOBITS: printf("NOBITS\n"); break;
			case SHT_REL: printf("REL\n"); break;
			case SHT_SHLIB: printf("SHLIB\n"); break;
			case SHT_DYNSYM: printf("DYNSYM\n"); break;
			case SHT_INIT_ARRAY: printf("INIT_ARRAY\n"); break;
			case SHT_FINI_ARRAY: printf("FINI_ARRAY\n"); break;
			case SHT_PREINIT_ARRAY: printf("PREINIT_ARRAY\n"); break;
			case SHT_GROUP: printf("GROUP\n"); break;
			case SHT_SYMTAB_SHNDX: printf("SYMTAB_SHNDX\n"); break;
			case SHT_NUM: printf("NUM\n"); break;
			case SHT_LOOS: printf("LOOS\n"); break;
			case SHT_GNU_ATTRIBUTES: printf("GNU_ATTRIBUTES\n"); break;
			case SHT_GNU_HASH: printf("GNU_HASH\n"); break;
			case SHT_GNU_LIBLIST: printf("GNU_LIBLIST\n"); break;
			case SHT_CHECKSUM: printf("CHECKSUM\n"); break;
			case SHT_LOSUNW: printf("LOSUNW\n"); break;
			case SHT_SUNW_COMDAT: printf("SUNW_COMDAT\n"); break;
			case SHT_SUNW_syminfo: printf("SUNW_syminfo\n"); break;
		}

		if (sht[i].sh_flags & SHF_WRITE) printf("\tWRITE\n");
		if (sht[i].sh_flags & SHF_ALLOC) printf("\tALLOC\n");
		if (sht[i].sh_flags & SHF_EXECINSTR) printf("\tEXECINSTR\n");
		if (sht[i].sh_flags & SHF_MASKPROC) printf("\tMERGE\n");

	}

	return 0;
}

int main(int argc, char *argv[]) {
    struct stat st;
    char *fname;

    if (argc > 1) fname = argv[1];

    if (stat(fname, &st) != 0) {
        perror("stat");
        return 1;
    }

    return print_shdr(fname, st.st_size);
}
