#include <proc.h>
#include <elf.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Phdr Elf64_Phdr
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Phdr Elf32_Phdr
#endif

size_t ramdisk_read(void *buf, size_t offset, size_t len);

static uintptr_t loader(PCB *pcb, const char *filename)
{
  Elf_Ehdr ehdr;
  Elf_Phdr phdr;
  ramdisk_read(&ehdr, 0, sizeof(Elf_Ehdr));
  for (int i = 0; i < ehdr.e_phnum; i++)
  {
    ramdisk_read(&phdr, ehdr.e_phoff + i * ehdr.e_phentsize, ehdr.e_phentsize);
    if (phdr.p_type == PT_LOAD)
    {
      ramdisk_read((void *)phdr.p_vaddr, phdr.p_offset, phdr.p_filesz);
    }
  }
  return ehdr.e_entry;
}

void naive_uload(PCB *pcb, const char *filename)
{
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void (*)())entry)();
}