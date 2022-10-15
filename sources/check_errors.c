#include "../includes/distro.h"
#include "../includes/globals.h"
#include "../includes/null.h"

#include <stdlib.h>

int check_operators(const char *expr)
{
    const char *ope_ptr = expr;

    if (Utils.is_in(ope_ptr[0], operators_without_minus))
        return Logger.error("Expression cannot start with an operator");
    if (Utils.contains(ope_ptr, operators) == NONE)
        return Logger.error("Expression must have at least one operator");
    do {
        ope_ptr = Utils.contains(ope_ptr + 1, operators);
        if (ope_ptr == NULL)
            break;
        if (ope_ptr + 1 == NULL)
            return Logger.error("Expression cannot end with an operator");
        char prev_ope = ope_ptr[-1];

        if (Utils.is_in(prev_ope, operators))
            return Logger.error("Cannot chain two operators");
    } while (1);
    return 0;
}

int check_parenthesis(const char *expr)
{
    int counter = 0;

    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(')
            counter++;
        else if (expr[i] == ')')
            counter--;
        if (counter < 0)
            return Logger.error("Cannot close parenthesis without opening one before");
    }
    if (counter != 0)
            return Logger.error("Too many closing parenthesis");
    return 0;
}

int check_allowed_chars(const char *expr)
{
    char tmp = 0;

    for (int i = 0; expr[i]; i++) {
        tmp = 0;
        for (int j = 0; allowed_chars[j]; j++) {
            if (expr[i] == allowed_chars[j]) {
                tmp = 1;
                break;
            }
        }
        if (tmp == 0)
            return Logger.error("Unallowed character");
    }
    return 0;
}

int check_errors(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (check_allowed_chars(av[1]) == 84)
        return 84;
    if (check_parenthesis(av[1]) == 84)
        return 84;
    if (check_operators(av[1]) == 84)
        return 84;
    return 0;
}