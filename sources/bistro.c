#include "../includes/bistro.h"
#include "../includes/null.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int bistro(const char *expr)
{
    char *without_parenthesis = handle_parenthesis(strdup(expr));
    char *result = NULL;

    if (without_parenthesis == NULL)
        return 84;
    result = process_expr(without_parenthesis);
    if (result == NULL)
        return 84;
    printf("Result: %s\n", result);
    free(result);
    return 0;
}