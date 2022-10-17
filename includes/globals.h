#ifndef GLOBALS_H_
#define GLOBALS_H_

#include "utils.h"
#include "logger.h"

extern const char *allowed_chars;
extern const char *numbers;
extern const char *operators;
extern const char *operators_without_minus;
extern const char priorities[2][4];

extern const utils_t Utils;
extern const logger_t Logger;

#endif /* !GLOBALS_H_ */
