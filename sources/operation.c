#include "../includes/bistro.h"
#include "../includes/null.h"

char *process_operation(char *operation, int ope_idx)
{
    switch (operation[ope_idx]) {
        case ('+'):
            return exec_infin_add(operation, ope_idx);
        case ('-'):
            return exec_infin_min(operation, ope_idx);
        case ('/'):
            return exec_infin_div(operation, ope_idx);
        case ('*'):
            return exec_infin_mult(operation, ope_idx);
        case ('\%'):
            return exec_infin_mod(operation, ope_idx);
        default:
            return NULL;
    }
}