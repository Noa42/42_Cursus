NAME = push_swap


CFLAGS  = -Wall -Wextra -Werror -g

SOURCES = algorithm.c errors.c libft.c move_a.c move_b.c push_swap.c set_up_fields.c sort_three.c split.c stack.c start.c utils.c

OBJETS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJETS)
	gcc $(CFLAGS) $(OBJETS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJETS)

fclean :
	rm -f $(NAME) $(OBJETS)

re: fclean $(NAME)

.PHONY: all clean fclean re
