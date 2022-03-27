#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]);
extern char **environ;
void call_main(uintptr_t *args)
{
    uintptr_t argc = *args;
    printf("argc: %ld\n", argc);

    args = (uintptr_t *)(args + 1);
    char **argv = (char **)(args);
    printf("argv: %s\n", argv[1]);
    assert(0);
    args = (uintptr_t *)(args + argc + 1);
    char **envp = (char **)(args);

    environ = envp;
    exit(main(argc, argv, envp));
    assert(0);
}
