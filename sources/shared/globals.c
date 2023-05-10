#include "../../includes/globals.h"

const char *allowed_chars = "0123456789+-/*\%()";
const char *numbers = "0123456789";
const char *operators = "+-/*\%";
const char *operators_without_minus = "+/*\%";
const char priorities[NBR_GROUP_PRIO][NBR_PRIO_PER_GROUP] = {"*/\%\0", "+-\0"};

const utils_t Utils = {
    contains,
    contains_other_than,
    is_a_number,
    is_not_a_number,
    is_in,
    is_not_in,
    count_occurence,
    str_reverse,
};

const logger_t Logger = {
    logger,
    error,
    success,
};