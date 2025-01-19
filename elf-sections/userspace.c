#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>

int print_shdr(const char *const fname, size_t size) {
    int fd = open(fname, O_RDONLY);
    char *p = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)p;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(p + ehdr->e_shoff);

    int shnum = ehdr->e_shnum;

    Elf64_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
    const char *const sh_strtab_p = p + sh_strtab->sh_offset;

    for (int i = 0; i < shnum; ++i) {
        printf("%2d: %4d '%s'\n", i, shdr[i].sh_name,
               sh_strtab_p + shdr[i].sh_name);
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
