#include "../includes/bistro.h"

#include <stdio.h>

int main(int ac, char **av)
{
    printf("Expression: %s\n", av[1]);
    if (check_errors(ac, av) == 84)
        return 84;
    return bistro(av[1]);
}