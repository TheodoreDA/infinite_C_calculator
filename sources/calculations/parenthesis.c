#include "../../includes/null.h"
#include "../../includes/bistro.h"
#include <stdlib.h>

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