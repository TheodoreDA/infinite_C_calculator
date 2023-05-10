#include "../../includes/globals.h"
#include <string.h>
#include <stdlib.h>

int char_to_int(char c) {
    char str[2];

    str[0] = c;
    str[1] = '\0';
    if (c < '0' || c > '9')
        return 0;
    return atoi(str);
}

char int_to_char(int nb) {
    return nb + '0';
}

char *exec_infin_add(char *operation, int ope_idx)
{
    int left_idx = ope_idx - 1;
    int right_idx = strlen(operation) - 1;
    int bonus = 0;
    char *result = malloc(sizeof(char) * (strlen(operation) + 1));

    memset(result, '\0', strlen(operation) + 1);
    do {
        int left = left_idx != -1? char_to_int(operation[left_idx]): 0;
        int right = Utils.is_a_number(operation[right_idx])? char_to_int(operation[right_idx]): 0;
        char res[2];
        res[0] = int_to_char((left + right + bonus) % 10);
        res[1] = '\0';
        bonus = left + right >= 10? 1: 0;

        strcat(result, res);
        if (left_idx != -1)
            left_idx--;
        if (right_idx != ope_idx)
            right_idx--;
    } while (left_idx != -1 || right_idx != ope_idx);

    Utils.str_reverse(result);
    return result;
}
