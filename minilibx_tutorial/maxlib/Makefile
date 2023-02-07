# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:21:52 by mwagner           #+#    #+#              #
#    Updated: 2023/02/03 19:39:10 by mwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program
NAME	= test

# Compilation
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)
FLAGLINUX	= -Lminilibx -lmlx -lXext -lX11 -lm
FLAGMAC		= -L/usr/X11/include -L/usr/X11/lib

# Includes
INC			= -I ./minilibx-linux/
	
# Sources
SRC_PATH = ./

SRC		=	lib.c 		\
			
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Colors
NC			:= \033[0m
RED			:= \033[0;31m
GREEN		:= \033[0;32m
BLUE		:= \033[0;34m

# Rules
$(NAME): $(MLX) $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX) $(FLAGLINUX) $(FLAGFT)
	@echo "$(BLUE) $(NAME) created $(NC)"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "$(GREEN)Compiling: $< $(NC)"
	@$(CC) -c $(CFLAGS) -o $@ $< $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@echo "$(GREEN) Creating MLX $< $(NC)"
	@make -C $(MLX_PATH)

all: $(NAME) 

bonus: all

clean:
	@echo "Cleaning: $(RED) $(OBJ_PATH) $(NC)"
	@make clean -C $(MLX_PATH)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "Cleaning:$(RED) $(NAME) $(NC)"
	@rm -f $(NAME)

re:	clean fclean all

.PHONY: all, libft, clean, fclean