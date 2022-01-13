NAME	=	libftprintf.a

SRCS	= 	ft_printf.c ft_puthex.c\
			ft_putstr_fd.c

HEADER	=	ft_printf.h 

OBJ	=		$(SRCS:%.c=%.o)

CC	=		gcc

CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all