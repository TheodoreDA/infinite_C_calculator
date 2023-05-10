#include "null.h"
#include "bool.h"
#include <criterion/criterion.h>
#include "globals.h"

#include <stdio.h>
#include <stdlib.h>

Test(contains, simple_working) {
    char str[] = "hello world";

    cr_assert_str_eq(Utils.contains(str, "w"), "world");
    cr_assert_str_eq(Utils.contains(str, "zpo"), "o world");
}

Test(contains, simple_uncorrect) {
    char str[] = "hello world";

    printf("%p\n", Utils.contains(str, "z"));
    printf("%p\n", NULL);
    cr_assert_str_eq(Utils.contains(str, "z"), NULL);
}

Test(str_reverse, simple_correct) {
    char s[] = "hello world";
    char *str = malloc(sizeof(char) * strlen(s));
    strcpy(str, s);

    Utils.str_reverse(str);
    cr_assert_str_eq(str, "dlrow olleh");
    free(str);
}
