# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborda <aborda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 10:00:00 by student           #+#    #+#              #
#    Updated: 2026/01/21 11:38:00 by aborda           ###   ########.fr        #
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
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iincludes

# Directories
OBJ_DIR		= objs

# Sources
SRC_LIBC	= srcs/libft/ft_isalpha.c \
			  srcs/libft/ft_isdigit.c \
			  srcs/libft/ft_isalnum.c \
			  srcs/libft/ft_isascii.c \
			  srcs/libft/ft_isprint.c \
			  srcs/libft/ft_strlen.c \
			  srcs/libft/ft_memset.c \
			  srcs/libft/ft_bzero.c \
			  srcs/libft/ft_memcpy.c \
			  srcs/libft/ft_memmove.c \
			  srcs/libft/ft_strlcpy.c \
			  srcs/libft/ft_strlcat.c \
			  srcs/libft/ft_toupper.c \
			  srcs/libft/ft_tolower.c \
			  srcs/libft/ft_strchr.c \
			  srcs/libft/ft_strrchr.c \
			  srcs/libft/ft_strncmp.c \
			  srcs/libft/ft_memchr.c \
			  srcs/libft/ft_memcmp.c \
			  srcs/libft/ft_strnstr.c \
			  srcs/libft/ft_atoi.c \
			  srcs/libft/ft_calloc.c \
			  srcs/libft/ft_strdup.c

SRC_ADD		= srcs/libft/ft_substr.c \
			  srcs/libft/ft_strjoin.c \
			  srcs/libft/ft_strtrim.c \
			  srcs/libft/ft_split.c \
			  srcs/libft/ft_itoa.c \
			  srcs/libft/ft_strmapi.c \
			  srcs/libft/ft_striteri.c \
			  srcs/libft/ft_putchar_fd.c \
			  srcs/libft/ft_putstr_fd.c \
			  srcs/libft/ft_putendl_fd.c \
			  srcs/libft/ft_putnbr_fd.c

SRC_BONUS	= srcs/libft/ft_lstnew_bonus.c \
			  srcs/libft/ft_lstadd_front_bonus.c \
			  srcs/libft/ft_lstsize_bonus.c \
			  srcs/libft/ft_lstlast_bonus.c \
			  srcs/libft/ft_lstadd_back_bonus.c \
			  srcs/libft/ft_lstdelone_bonus.c \
			  srcs/libft/ft_lstclear_bonus.c \
			  srcs/libft/ft_lstiter_bonus.c \
			  srcs/libft/ft_lstmap_bonus.c

SRC_PERSO	= srcs/libft/ft_intlen.c \
			  srcs/libft/ft_longlen.c \
			  srcs/libft/ft_unsignedint_len.c \
			  srcs/libft/ft_putunsignedint_fd.c \
			  srcs/libft/ft_isspace.c \
			  srcs/libft/ft_is_valid_int.c \
			  srcs/libft/ft_atol.c

SRC_PRINTF	= srcs/ft_printf/ft_printf.c \
			  srcs/ft_printf/ft_print_char.c \
			  srcs/ft_printf/ft_print_str.c \
			  srcs/ft_printf/ft_print_pointer.c \
			  srcs/ft_printf/ft_print_decimal.c \
			  srcs/ft_printf/ft_print_unsigned_decimal.c \
			  srcs/ft_printf/ft_print_hexalower.c \
			  srcs/ft_printf/ft_print_hexaupper.c \
			  srcs/ft_printf/ft_print_percent.c

SRC_GNL		= srcs/get_next_line/get_next_line_bonus.c \
			  srcs/get_next_line/get_next_line_utils_bonus.c

SRCS		= $(SRC_LIBC) $(SRC_ADD) $(SRC_PERSO) $(SRC_PRINTF) $(SRC_BONUS) $(SRC_GNL)

# Objects
OBJS		= $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)✓$(RESET) Compiled: $(CYAN)$<$(RESET)"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)==========================================$(RESET)"
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"
	@echo "$(GREEN)==========================================$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)✓ $(NAME) Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)✓ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
