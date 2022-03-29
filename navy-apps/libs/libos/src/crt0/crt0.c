#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]);
extern char **environ;
void call_main(uintptr_t *args)
{
    uintptr_t argc = *args;

    args = (uintptr_t *)(args + 1 + 1);
    char **argv = (char **)(args);

    for (int i = 0; i < argc; i++)
    {
        printf("call_main: argv %d = %s\n", i, argv[i]);
    }

    args = (uintptr_t *)(args + argc + 1);
    char **envp = (char **)(args);

    environ = envp;
    printf("000\n");
    exit(main(argc, argv, envp));
    assert(0);
}
