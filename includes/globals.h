#ifndef GLOBALS_H_
#define GLOBALS_H_

#include "utils.h"
#include "logger.h"

#define NBR_GROUP_PRIO 2
#define NBR_PRIO_PER_GROUP 4

extern const char *allowed_chars;
extern const char *numbers;
extern const char *operators;
extern const char *operators_without_minus;
extern const char priorities[NBR_GROUP_PRIO][NBR_PRIO_PER_GROUP];

extern const utils_t Utils;
extern const logger_t Logger;

#endif /* !GLOBALS_H_ */
