#include "../../includes/null.h"
#include "../../includes/globals.h"
#include <string.h>

const char *contains(const char *haystack, const char *needles)
{
    for (int i = 0; haystack[i]; i++) {
        for (int j = 0; needles[j]; j++) {
            if (haystack[i] == needles[j])
                return &haystack[i];
        }
    }
    return NULL;
}

char contains_other_than(const char *str, const char *to_exclude)
{
    for (int i = 0; str[i]; i++) {
        char tmp = 0;

        for (int j = 0; to_exclude[j]; j++) {
            if (str[i] == to_exclude[j]) {
                tmp = 1;
                break;
            }
        }
        if (tmp == 0)
            return 1;
    }
    return 0;
}

char is_a_number(const char c)
{
    for (int i = 0; numbers[i]; i++) {
        if (c == numbers[i])
            return 1;
    }
    return 0;
}

char is_not_a_number(const char c)
{
    for (int i = 0; numbers[i]; i++) {
        if (c == numbers[i])
            return 0;
    }
    return 1;
}

char is_in(const char c, const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

char is_not_in(const char c, const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return 0;
    }
    return 1;
}

int count_occurence(const char *haystack, const char needle)
{
    int counter = 0;

    for (int i = 0; haystack[i]; i++) {
        if (haystack[i] == needle)
            counter++;
    }
    return counter;
}

void str_reverse(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];

        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}
