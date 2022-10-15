#ifndef UTILS_H_
#define UTILS_H_

struct s_utils {
    const char *(* contains)(const char *haystack, const char *needles);
    char (* is_in)(const char c, const char *str);
    char (* is_not_in)(const char c, const char *str);
    int (* count_occurence)(const char *haystack, const char needle);
};
typedef struct s_utils utils_t;

const char *contains(const char *haystack, const char *needles);
char is_in(const char c, const char *str);
char is_not_in(const char c, const char *str);
int count_occurence(const char *haystack, const char needle);


#endif /* !UTILS_H_ */
