NAME	=		unit_tests

SRC		=		sources/test_utils.c			\
				../sources/shared/utils.c		\
				../sources/shared/globals.c		\
				../sources/logger.c

OBJ		=		$(SRC:%.c=%.o)

CC		=		gcc

RM		=		rm -f

INCLUDES	=		-I../includes

CFLAGS		=		$(INCLUDES) --coverage -g -O0

LDFLAGS		=		-lcriterion

$(NAME):	all

all:		$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) sources/*.gc*

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
