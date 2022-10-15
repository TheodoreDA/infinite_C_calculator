#include <stdarg.h>
#include <stdio.h>

int logger(const char *message, int code)
{
    printf("%s\n", message);
    return code;
}

int error(const char *message)
{
    printf("ERROR: %s\n.", message);
    return 84;
}

int success(const char *message)
{
    printf("%s\n.", message);
    return 0;
}