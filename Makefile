NAME		=		bistro

SRC			=		sources/main.c							\
					sources/check_errors.c					\
					sources/shared/globals.c				\
					sources/bistro.c						\
					sources/calculations/parenthesis.c		\
					sources/calculations/expr.c				\
					sources/calculations/operation.c		\
					sources/infin_operations/infin_add.c	\
					sources/infin_operations/infin_min.c	\
					sources/infin_operations/infin_div.c	\
					sources/infin_operations/infin_mult.c	\
					sources/infin_operations/infin_mod.c	\
					sources/shared/utils.c					\
					sources/logger.c

OBJ			=		$(SRC:%.c=%.o)

CC			=		gcc

RM			=		rm -f

CFLAGS		=		-W -Wall -Wshadow -Wextra 

LDFLAGS		=		

$(NAME):		all

all:			$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) sources/*.gc*
	$(RM) sources/shared/*.gc*
	$(RM) sources/calculations/*.gc*
	$(RM) sources/infin_operations/*.gc*
	$(RM) coverage*
	$(RM) vgcore.*
	$(MAKE) -C tests/ clean

fclean:			clean
	$(RM) $(NAME)
	$(MAKE) -C tests/ fclean

re:				fclean all

debug:			CFLAGS += -g
debug:			re

tests_run:		fclean
	$(MAKE) -C tests
	./tests/unit_tests

coverage:		fclean
coverage:		tests_run
	gcovr -e tests/

html_coverage:	fclean
html_coverage:	tests_run
	gcovr -e tests/ --html-details coverage.html
	xdg-open coverage.html