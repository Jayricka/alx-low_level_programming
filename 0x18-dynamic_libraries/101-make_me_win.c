#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

/**
 * puts - Overrides the puts function to display a winning message.
 * @str: The string to be displayed (unused).
 *
 * Return: Always returns the result of the original puts function.
 */
typedef int (*puts_func)(const char *);

int puts(const char *str __attribute__((unused)))
{
    puts_func original_puts;
    void *handle = dlopen("libc.so.6", RTLD_LAZY);
    *(void **)(&original_puts) = dlsym(handle, "puts");
    dlclose(handle);

    return original_puts("Congratulations! You won the Jackpot!");
}
