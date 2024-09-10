NAME = so_long

USER = achacon-

MLXFLAGS = -I ./MLX42/include -ldl -lglfw -pthread -lm -fPIE

CFLAGS  = -Wall -Wextra -Werror -g -no-pie

CC = gcc

MLX42 = ./MLX42/

LIBFT = libft/

PRINTF = ft_printf/

SRC_DIR = src/

OBJ_DIR = obj/

SRC_FILES = main parsing_map parsing_utils map gameplay utils

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@make -C $(MLX42)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(PRINTF) -lftprintf -L$(MLX42) -lmlx42 $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -frf $(OBJ_DIR)
			@make clean -C $(MLX42)
			@make clean -C $(LIBFT)
			@make clean -C $(PRINTF)
			@make all clean -C

fclean:
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@make fclean -C $(MLX42)
			@make clean -C $(LIBFT)
			@make clean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re