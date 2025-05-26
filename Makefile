CC = cc
CFLAGS =  -Wall -Wextra -Werror -Iinc

MLX_DIR = /usr/include/minilibx-linux

MLX_LINK = -L$(MLX_DIR) -lmlx -lXext -lX11

NAME = so_long
BONUS_NAME = so_long_bonus
SRCS = ft_split.c main.c utils1.c utls.c utils2.c utils3.c utils4.c utils5.c utils6.c read_map.c 
SRC_BONUS = bonus/ft_split_bonus.c bonus/main_bonus.c bonus/utils1_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c bonus/utils3_bonus.c \
			bonus/utils4_bonus.c bonus/utils5_bonus.c bonus/utils6_bonus.c bonus/read_map_bonus.c bonus/itoa_bonus.c bonus/utils7_bonus.c
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER =  so_long.h
HEADERB = bonus/so_long_bonus.h

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LINK) -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_LINK) -o $(BONUS_NAME)

$(OBJ): $(HEADER)
$(OBJ_BONUS): $(HEADERB)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean bonus re
