#include <dlfcn.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "common.h"

typedef uint64_t paddr_t;
typedef uint64_t vaddr_t;
extern Vtop *top;
extern void isa_reg_display()

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
void difftest_skip_ref()
{
    is_skip_ref = true;
    // If such an instruction is one of the instruction packing in QEMU
    // (see below), we end the process of catching up with QEMU's pc to
    // keep the consistent behavior in our best.
    // Note that this is still not perfect: if the packed instructions
    // already write some memory, and the incoming instruction in NEMU
    // will load that memory, we will encounter false negative. But such
    // situation is infrequent.
    skip_dut_nr_inst = 0;
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut)
{
    skip_dut_nr_inst += nr_dut;

    while (nr_ref-- > 0)
    {
        ref_difftest_exec(1);
    }
}

void init_difftest(char *ref_so_file, long img_size, uint64_t *difftest_regs)
{
    assert(ref_so_file != NULL);

    void *handle;
    handle = dlopen(ref_so_file, RTLD_LAZY | RTLD_DEEPBIND);
    assert(handle);

    ref_difftest_memcpy = dlsym(handle, "difftest_memcpy");
    assert(ref_difftest_memcpy);

    ref_difftest_regcpy = dlsym(handle, "difftest_regcpy");
    assert(ref_difftest_regcpy);

    ref_difftest_exec = dlsym(handle, "difftest_exec");
    assert(ref_difftest_exec);

    ref_difftest_raise_intr = dlsym(handle, "difftest_raise_intr");
    assert(ref_difftest_raise_intr);

    void(*ref_difftest_init) = dlsym(handle, "difftest_init");
    assert(ref_difftest_init);

    ref_difftest_init();
    ref_difftest_memcpy(0x80000000, guest_to_host(0x80000000), img_size, 1);
    ref_difftest_regcpy(difftest_regs, 1);
}

void difftest_step(uint64_t *difftest_regs, uint64_t pc)
{
    uint64_t ref_r[33];

    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, 0);

    bool is_different = false;

    for (int i = 0; i < 33; i++)
    {
        if (difftest_regs[i] != ref_r[i])
        {
            printf("reg %2d is different after executing instruction at pc 0x%08lx, right= 0x%16lx, wrong = 0x%16lx\n", i, top->pc, ref_r[i], difftest_regs[i]);
            is_different = true;
        }
    }

    if(is_different)
    {
        isa_reg_display();
        return 1;
    }

    return 0;
    
}