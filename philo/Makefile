NAME = philo

USER = achacon-

CFLAGS  = -Wall -Wextra -Werror -g -pthread

CC = gcc

SRC_DIR = src/

OBJ_DIR = obj/

SRC_FILES = main utils

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -frf $(OBJ_DIR)
			@make all clean -C

fclean:
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re