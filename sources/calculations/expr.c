#include "../../includes/bistro.h"
#include "../../includes/null.h"
#include "../../includes/globals.h"
#include <stdlib.h>
#include <string.h>

// TODO: check if - is an operator or negative nbr
int find_next_operator(char *expr)
{
    int prio_idx = 0;

    while (priorities[prio_idx]) {
        for (int i = 0; expr[i]; i++) {
            for (int j = 0; priorities[prio_idx][j]; j++) {
                if (expr[i] == priorities[prio_idx][j])
                    return i;
            }
        }
        prio_idx++;
    }
    return -1;
}

//     1+23+45/67-8*9
char *process_expr(char *expr)
{
    int ope_idx = find_next_operator(expr);
    char *operation = calloc(strlen(expr) + 1, sizeof(char));
    char *result = NULL;
    int i = 0;
    int j = 0;

    while (ope_idx != -1) {
        memset(operation, 0, strlen(expr));
        for (i = ope_idx + 1; expr[i]; i++) {
            if (Utils.is_not_a_number(expr[i]))
                break;
        }
        // TODO: Check for this case:     1+-1*2
        for (j = ope_idx - 1; expr[j]; j--) {
            if (Utils.is_not_a_number(expr[j]))
                break;
        }
        j++;
        for (int k = 0; j != i; j++)
            operation[k++] = expr[j];
        result = process_operation(operation, find_next_operator(operation));
        if (result == NULL) {
            free(operation);
            return NULL;
        }
        // HERE

        free(result);
        ope_idx = find_next_operator(expr);
    }
    free(operation);
    return expr;
}