CC = gcc
PRINTF = _printf.h _printf.c _putchar.c get_print_functions.c use_cases.c more_use_cases.c utils.c
SRC = shell.h main.c split.c
OBJ = $(SRC:.c=.o)
NAME = school
CFLAGS = -Wall -Werror -Wextra -pedantic
RM = rm -f

all: $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			$(CC) $(CFLAGS) $(OBJ) -o holberton

clean:
		$(RM) *~ $(NAME)

oclean:
		$(RM) $(OBJ)

fclean: clean oclean

re: oclean all
