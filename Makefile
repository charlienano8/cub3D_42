# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborda <aborda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 16:43:56 by aborda            #+#    #+#              #
#    Updated: 2026/06/30 08:42:45 by aborda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
RESET		= \033[0m

# Project
NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iincludes -I./libft/includes -I$(MLX_DIR)

# Minilibx
MLX_DIR		= minilibx-linux
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Library
LIBFT 		= ./libft/libft.a
MLX_LIB 	= $(MLX_DIR)/libmlx.a

# Directories
OBJ_DIR		= objs

# VPATH
VPATH 		= srcs:srcs/game:srcs/messages:srcs/parsing:srcs/utils:srcs/raycasting

# Sources
SRCS_MAIN	= main.c \
			  messages.c \
			  create_map.c \
			  check_map_elements.c

SRCS_UTILS	= is_cub_extension.c \
			  is_map_line.c \
			  line_map_count.c

SRCS_GAME 	= init_game.c \
			  draw.c \
			  events.c

SRCS_RAYCASTING = engine.c

SRCS 		= $(SRCS_MAIN) \
			  $(SRCS_UTILS) \
			  $(SRCS_GAME) \
			  $(SRCS_RAYCASTING) \

# Objects
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(LIBFT):
	@make -C libft

$(MLX_DIR):
	@./add_minilibx.sh

$(MLX_LIB): | $(MLX_DIR)
	@make -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)✓$(RESET) Compiled: $(CYAN)$<$(RESET)\n"

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)==========================================$(RESET)\n"
	@printf "$(GREEN)✓ $(NAME) created successfully!$(RESET)\n"
	@printf "$(GREEN)==========================================$(RESET)\n"

clean:
	@make clean -C libft
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)
	@printf "$(YELLOW)✓ Object files removed$(RESET)\n"

fclean: clean
	@make fclean -C libft
	@make clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)
	@printf "$(YELLOW)✓ $(NAME) removed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
