# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 11:35:29 by mwagner           #+#    #+#              #
#    Updated: 2022/11/10 12:30:56 by mwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	./srcs/ft_isalpha.c	\
		./srcs/ft_isdigit.c	\
		./srcs/ft_isalnum.c	\
		./srcs/ft_isascii.c	\
		./srcs/ft_isprint.c	\
		./srcs/ft_strlen.c	\
		./srcs/ft_memset.c	\
		./srcs/ft_bzero.c	\
		./srcs/ft_memcpy.c	\
		./srcs/ft_memmove.c	\
		./srcs/ft_strlcpy.c	\
		./srcs/ft_strlcat.c	\
		./srcs/ft_toupper.c	\
		./srcs/ft_tolower.c	\
		./srcs/ft_strchr.c	\
		./srcs/ft_strrchr.c	\
		./srcs/ft_strcmp.c	\
		./srcs/ft_strncmp.c	\
		./srcs/ft_memchr.c	\
		./srcs/ft_memcmp.c	\
		./srcs/ft_strnstr.c	\
		./srcs/ft_atoi.c	\
		./srcs/ft_calloc.c	\
		./srcs/ft_strdup.c	\
		./srcs/ft_substr.c	\
		./srcs/ft_strjoin.c	\
		./srcs/ft_strtrim.c	\
		./srcs/ft_split.c	\
		./srcs/ft_itoa.c	\
		./srcs/ft_strmapi.c	\
		./srcs/ft_striteri.c	\
		./srcs/ft_putchar_fd.c	\
		./srcs/ft_putstr_fd.c	\
		./srcs/ft_putendl_fd.c	\
		./srcs/ft_putnbr_fd.c	\
		
SRC_BONUS = ./srcs_bonus/ft_lstnew.c 		\
			./srcs_bonus/ft_lstadd_front.c	\
			./srcs_bonus/ft_lstsize.c		\
			./srcs_bonus/ft_lstlast.c		\
			./srcs_bonus/ft_lstadd_back.c	\
			./srcs_bonus/ft_lstdelone.c		\
			./srcs_bonus/ft_lstclear.c		\
			./srcs_bonus/ft_lstiter.c		\

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes/libft.h
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(SRC_BONUS:.c=.o)
GNL_OBJS = $(SRC_GNL:.c=.o)

NC			:= \033[0m
RED 		:= \033[0;31m
GREEN 		:= \033[0;32m
BLUE 		:= \033[0;34m

all: $(NAME)

%.o : %.c $(HEADER)
	@echo "$(GREEN)Compiling: $< $(NC)"
	@$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJS)
	@ar r $(NAME) $(OBJS)
	@echo "$(BLUE)$(NAME) created $(NC)"

bonus: $(OBJS) $(BONUS_OBJS)
	@ar r $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(BLUE)$(NAME) Bonus created$(NC)"

gnl: $(OBJS) $(GNL_OBJS)
	@ar r $(NAME) $(OBJS) $(GNL_OBJS)
	@echo "$(BLUE)$(NAME) get_next_line created$(NC)"

clean:
	@echo "Cleaning:$(RED) $(OBJS) $(NC)"
	@rm -f $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)

fclean:
	@echo "Cleaning:$(RED) $(NAME) $(NC)"
	@rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re bonus
