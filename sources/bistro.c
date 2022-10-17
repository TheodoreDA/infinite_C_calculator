#include "../includes/bistro.h"
#include "../includes/globals.h"
#include "../includes/null.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* TODO:
 *     - / 0
 *     - 
 *     - 
 *     - 
*/

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

char *handle_parenthesis(char *expr) {
    int i = 0;
    int j = 0;
    int k = 0;
    char *sub_expr = NULL;
    char *result = NULL;

    // Go to first ending priority parenthesis
    for (; expr[i] && expr[i] != ')'; i++);
    // If none found, then exit with expr
    if (expr[i] == 0)
        return expr;
    // While not to opening parenthesis, continue going left
    for (j = i; expr[j] != '('; j--);
    // Allocate memory to the length of the parenthesis
    sub_expr = calloc(i - j + 1, sizeof(char));
    // Set tmp idx to copy inner expr of parenthesis
    k = j + 1;
    // Copy inner expr of parenthesis to newly allocated memory
    for (int l = 0; expr[k] != ')'; k++)
        sub_expr[l++] = expr[k];
    // Process expr, and set result to another var
    result = process_expr(sub_expr);
    if (result == NULL) {
        free(sub_expr);
        return NULL;
    }
    // Override expr's parenthesis with result (it should be smaller than inner expr)
    for (int l = 0; result[l]; l++)
        expr[j++] = result[l];
    // Offset the end of the expr to after the pasted result
    for (i += 1; expr[i]; i++)
        expr[j++] = expr[i];
    // Add forced null char
    expr[j] = '\0';
    // Free resources (don't free sub_expr because process_expr doesn't malloc, it uses the ptr given)
    free(result);
    return expr;
}

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
    free(without_parenthesis);
    free(result);
    return 0;
}