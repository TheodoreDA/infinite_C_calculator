#include <string.h>

char *exec_infin_mod(char *operation, int ope_idx)
{
    (void) ope_idx;
    return strdup(operation);;
}