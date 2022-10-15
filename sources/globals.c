#include "../includes/globals.h"

const char *allowed_chars = "0123456789+-/*\%()";
const char *operators = "+-/*\%";
const char *operators_without_minus = "+/*\%";

const utils_t Utils = {
    contains,
    contains_other_than,
    is_in,
    is_not_in,
    count_occurence,
};

const logger_t Logger = {
    logger,
    error,
    success,
};