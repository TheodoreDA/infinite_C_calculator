#include "../includes/null.h"

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

char contains_other_than(const char *str, const char *allowed_chars)
{
    for (int i = 0; str[i]; i++) {
        char tmp = 0;

        for (int j = 0; allowed_chars[j]; j++) {
            if (str[i] == allowed_chars[j]) {
                tmp = 1;
                break;
            }
        }
        if (tmp == 0)
            return 1;
    }
    return 0;
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