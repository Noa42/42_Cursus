NAME = pipex


CFLAGS  = -Wall -Wextra -Werror -g

SOURCES = ft_split.c ft_strjoin.c ft_strncmp.c utils.c process.c main.c 

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
