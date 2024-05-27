NAME	:=	libftprintf.a

CC	:=	cc
CFLAGS	:=	-Wall	-Wextra	-Werror

SOURCES	:=	ft_putchar.c	\
			ft_putstr.c	\
			ft_putaddress.c	\
			ft_putnbr.c	\
			ft_putunbr.c	\
			ft_putxnbr_uppercase.c	\
			ft_printf.c

OBJECTS	:=	$(SOURCES:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
	ar	rcs	$(NAME)	$(OBJECTS)

%.o:	%.c
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

clean:
	rm	-f	$(OBJECTS)

fclean:	clean
	rm	-f	$(NAME)

re:	fclean	$(NAME)

.PHONY:	all	clean	fclean	re