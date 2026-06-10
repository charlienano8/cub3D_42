NAME = cub3D

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft

SRCS = main.c events.c\

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/include

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) minilibx-linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make clean -C minilibx-linux

fclean: clean
	$(RM) $(NAME) so_long
	make -C $(LIBFT_DIR) fclean
	$(RM) minilibx-linux/libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re
