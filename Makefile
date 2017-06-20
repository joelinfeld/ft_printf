NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS=$(wildcard *.c)
LIBSRCS=$(wildcard libft/*.c)
OBJS=$(SRCS:%.c=%.o)
LIBOBJS=libft/$(LIBSRCS:%.c=%.o)
INC=libft/libft.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBOBJS)
	ar rc $(NAME) $(OBJS) $(LIBOBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $(SRCS) $(LIBSRCS)

clean:
	-rm -f $(OBJS)
	-rm -f $(wildcard *.o)

fclean: clean
	-rm -f $(NAME)

re: fclean all
