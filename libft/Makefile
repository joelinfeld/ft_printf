NAME = libft.a

SRC = $(wildcard *.c)

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	gcc -Wall -Wextra -Werror -c $(SRC) -Iincludes/
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
