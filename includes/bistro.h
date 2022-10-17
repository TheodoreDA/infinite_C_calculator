#ifndef BISTRO_H_
#define BISTRO_H_

int check_errors(int ac, char **av);
int bistro(const char *expr);
char *exec_infin_add(char *operation, int ope_idx);
char *exec_infin_min(char *operation, int ope_idx);
char *exec_infin_div(char *operation, int ope_idx);
char *exec_infin_mult(char *operation, int ope_idx);
char *exec_infin_mod(char *operation, int ope_idx);

#endif /* !BISTRO_H_ */
