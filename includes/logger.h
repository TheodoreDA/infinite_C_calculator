#ifndef LOGGER_H_
#define LOGGER_H_

struct s_logger {
    int (* logger)(const char *message, int code);
    int (* error)(const char *message);
    int (* success)(const char *message);
};
typedef struct s_logger logger_t;

int logger(const char *message, int code);
int error(const char *message);
int success(const char *message);

#endif /* !LOGGER_H_ */
