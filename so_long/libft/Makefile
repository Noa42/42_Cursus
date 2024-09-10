NAME = libft.a
NAME_BONUS = libft.a
SOURCES = ft_memset.c ft_bzero.c ft_strlen.c ft_isdigit.c ft_isalpha.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_memchr.c ft_memcpy.c\
ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_calloc.c ft_substr.c ft_strdup.c ft_strjoin.c\
ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c ft_memcmp.c ft_memmove.c\
 ft_itoa.c ft_split.c ft_atoi.c 

OBJETOS = $(SOURCES:.c=.o)

SOURCES_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstiter_bonus.c  ft_lstclear_bonus.c ft_lstmap_bonus.c

OBJETOS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJETOS)
	ar rcs $(NAME) $(OBJETOS)

%.o: %.c
	gcc -Wall -Wextra -Werror -c -o $@ $<

clean :
	rm -f $(OBJETOS) $(OBJETOS_BONUS)

fclean :
	rm -f $(NAME) $(OBJETOS) $(OBJETOS_BONUS)

re: fclean $(NAME)

bonus: $(OBJETOS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJETOS_BONUS)

.PHONY: all clean fclean re bonus