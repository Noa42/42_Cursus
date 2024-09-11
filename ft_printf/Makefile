NAME = libftprintf.a

SOURCES = ft_printf.c nbr_base.c c_print.c i_print.c u_print.c x_print.c p_print.c s_print.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

OBJETS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJETS)
	ar rcs $(NAME) $(OBJETS)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJETS)

fclean :
	rm -f $(NAME) $(OBJETS)

re: fclean $(NAME)

.PHONY: all clean fclean re