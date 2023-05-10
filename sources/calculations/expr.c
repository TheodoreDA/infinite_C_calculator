#include "../../includes/bistro.h"
#include "../../includes/null.h"
#include "../../includes/globals.h"
#include <stdlib.h>
#include <string.h>

int find_next_operator(char *expr)
{
    int prio_idx = 0;

    while (prio_idx < NBR_GROUP_PRIO) {
        for (int i = 0; expr[i]; i++) {
            for (int j = 0; priorities[prio_idx][j]; j++) {
                if (expr[i] == priorities[prio_idx][j]) {
                    // Check when a minus found, wether it has an operator before
                    if (expr[i] == '-') {
                        if (i != 0 && Utils.is_not_a_number(expr[i - 1]))
                            return i - 1;
                    }
                    return i;
                }
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
    char *operation = malloc(sizeof(char) * (strlen(expr) + 1));
    char *result = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    while (ope_idx != -1) {
        memset(operation, '\0', strlen(expr) + 1);

        // Find the boundries of the targeted operation
        for (i = ope_idx + 1; expr[i]; i++) {
            if (Utils.is_not_a_number(expr[i])) {
                if (expr[j] != '-')
                    break;
                if (i != ope_idx + 1)
                    break;
            }
        }
        for (j = ope_idx - 1; j > 0; j--) {
            if (Utils.is_not_a_number(expr[j])) {
                if (expr[j] != '-')
                    break;
                if (Utils.is_not_a_number(expr[j - 1]))
                    break;
            }
        }

        // Process the targeted operation
        k = j;
        for (int l = 0; k != i; k++) {
            operation[l++] = expr[k];
            operation[l] = '\0';
        }
        result = process_operation(operation, find_next_operator(operation));
        if (result == NULL) {
            free(operation);
            return NULL;
        }

        // Place result of targeted operation into expr
        for (int l = 0; result[l]; l++)
            expr[j++] = result[l];
        for (; expr[i]; i++)
            expr[j++] = expr[i];
        expr[j] = '\0';

        free(result);
        ope_idx = find_next_operator(expr);
    }
    free(operation);
    return expr;
}