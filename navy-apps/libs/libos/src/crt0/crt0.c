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
    printf("call_main: argv 0 = %s\n", argv[0]);
    printf("call_main: argv 1 = %s\n", argv[1]);
    printf("call_main: argv 2 = %s\n", argv[2]);

    args = (uintptr_t *)(args + argc + 1);
    char **envp = (char **)(args);

    environ = envp;
    exit(main(argc, argv, envp));
    assert(0);
}
