NAME		=		bistro

SRC		=		sources/main.c				\
				sources/check_errors.c		\
				sources/globals.c			\
				sources/bistro.c			\
				sources/utils.c				\
				sources/logger.c

OBJ		=		$(SRC:%.c=%.o)

CC		=		gcc

RM		=		rm -f

INCLUDES	=		-Iinclude

CFLAGS		=		-W -Wall -Wshadow -Wextra $(INCLUDES)

LDFLAGS		=		

$(NAME):	all

all:		$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) include/*~
	$(RM) sources/*~

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re
