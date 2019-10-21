NAME = afedoren.filler

FLAG = -Wall -Wextra -Werror

DEL = rm -rf

HDR = fillit.h

PATH = /bin/

SRC =	main.c \
		get_next_line.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strstr.c \
		ft_isdigit.c \
		ft_atoi.c \
		ft_strcpy.c \
		map.c \
		piece.c \
		algorithm.c \
		ft_bzero.c \
		ft_putnbr.c \
		ft_putchar.c \
		distance.c \
		ft_abs.c \
		ft_tolower.c \
		help.c \

SRCVISUAL = ft_atoi.c ft_isdigit.c ft_strdel.c get_next_line.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncpy.c ft_strnew.c ft_strcat.c ft_memset.c ft_strstr.c

OBJVISUAL = $(SRCVISUAL:.c=.o)

OBJ =	main.o \
		get_next_line.o \
		ft_memset.o \
		ft_strcat.o \
		ft_strchr.o \
		ft_strdel.o \
		ft_strdup.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_strncpy.o \
		ft_strnew.o \
		ft_strstr.o \
		ft_isdigit.o \
		ft_atoi.o \
		ft_strcpy.o \
		map.o \
		piece.o \
		algorithm.o \
		ft_bzero.o \
		ft_putnbr.o \
		ft_putchar.o \
		distance.o \
		ft_abs.o \
		ft_tolower.o \
		help.o \
		


all: $(NAME)

$(NAME) : $(OBJ)
		@gcc $(FLAG) $(OBJ) -o $(NAME)
		gcc $(FLAG) $(OBJVISUAL) -o visual visual.c 

%.o: %.c
		@gcc $(FLAG) -c $<

clean:
		$(DEL) $(OBJ)

fclean: clean
		$(DEL) $(NAME)
		@ /bin/rm -f visual

re: fclean all
