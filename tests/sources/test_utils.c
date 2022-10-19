#include "null.h"
#include "bool.h"
#include <criterion/criterion.h>

Test(simple, test) {
    cr_assert_str_eq("0", "0");
}