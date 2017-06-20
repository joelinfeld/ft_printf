NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBOBJS)
	ar rc $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
