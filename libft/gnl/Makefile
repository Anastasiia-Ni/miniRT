NAME 	= gnl.a
SRC 	= get_next_line.c get_next_line_utils.c

OBJ 	= $(SRC:.c=.o)
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
LIBC 	= ar -rcs
RM 		= rm -rf

all: ${NAME}

${NAME}:	$(OBJ)
			@gcc -c $(CFLAGS) $(SRC)
			@ar rc $(NAME) $(OBJ)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
