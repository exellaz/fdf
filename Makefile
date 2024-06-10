# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 14:33:10 by kkhai-ki          #+#    #+#              #
#    Updated: 2024/06/10 16:30:06 by kkhai-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
ORANGE = \033[0;38;5;166m

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

INCLUDE = -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)

SRC_DIR = src

SRC_FILES =	main			\
			parsing			\
			bresenham		\
			rendering		\
			rotation		\
			color			\
			projections		\
			transformations	\
			rgb				\
			key_handlers	\
			utils			\
			side_bar		\

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OS_UNAME = $(shell uname -s)
ifeq ($(OS_UNAME), Darwin)
	MLX_DIR = mlx/mlx_macOS
	LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else ifeq ($(OS_UNAME), Linux)
	MLX_DIR = mlx/mlx_linux
	LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
else
	$(Unsupported OS)
endif

all :
		@mkdir -p $(OBJ_DIR)
		@make -C libft
		@make -C $(MLX_DIR) >/dev/null 2>&1 && echo "$(GREEN)mlx created.$(RESET)"
		@make $(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) :	$(OBJ)
			@printf "$(GREEN)fdf object files created.$(RESET)\n"
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBRARIES) && echo "$(GREEN)fdf created.$(RESET)"

clean :
			@rm -rf $(OBJ_DIR) && echo "$(RED)fdf object files deleted.$(RESET)"
			@make clean -C $(LIBFT_DIR)
			@make clean -C $(MLX_DIR) >/dev/null 2>&1 && echo "$(RED)mlx cleaned.$(RESET)"

fclean:
			@rm -rf $(OBJ_DIR) $(NAME) && echo "$(RED)fdf deleted.$(RESET)"
			@rm -rf $(OBJ_DIR) && echo "$(RED)fdf object files deleted.$(RESET)"
			@make clean -C $(MLX_DIR) >/dev/null 2>&1
			@make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:	clean fclean re all
