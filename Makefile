# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 11:35:52 by akotzky           #+#    #+#              #
#    Updated: 2021/06/11 11:29:57 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRV	=	server
NAME_CLI	=	client

LIBFT		=	libft.a

SRC_SRV		:=	srcs/server.c
SRC_CLI		:=	srcs/client.c

OBJ_SRV		=	$(SRC_SRV:.c=.o)
OBJ_CLI		=	$(SRC_CLI:.c=.o)

INCLS		=	-Iincls

CFLAGS		=	-Wall -Wextra -Werror 
CC			=	gcc

.PHONY	:	all bonus clean fclean re

all : $(LIBFT) $(NAME_SRV) $(NAME_CLI)

$(NAME_SRV) :  $(OBJ_SRV)
	@echo "- Assembling Minitalk object files..."
	@echo "- Linking Minitalk server files..."
	@$(CC) $(CFLAGS) $(OBJ_SRV) -L . -lft -o $(NAME_SRV)

$(NAME_CLI) : $(OBJ_CLI)
	@echo "- Linking Minitalk client files..."
	@$(CC) $(CFLAGS) $(OBJ_CLI) -L . -lft -o $(NAME_CLI)

$(LIBFT) :
	@make -C ./libft all
	@cp ./libft/$(LIBFT) .
	@cp ./libft/incls/libft.h ./incls
	@cp ./libft/incls/ft_printf.h ./incls 
	@cp ./libft/incls/get_next_line.h ./incls

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

clean :
	@echo "- Cleaning Minitalk object files..."
	@rm -rf $(OBJ_SRV) $(OBJ_CLI)

fclean : clean
	@echo "- Cleaning Minitalk header, binary and library files..."
	@rm -rf incls/libft.h incls/ft_printf.h incls/get_next_line.h $(NAME_SRV) $(NAME_CLI) $(LIBFT)
	@make -C ./libft clean

libftclean : 
	@make -C ./libft fclean

echore :
	@printf "\e[1;32m"
	@echo "\n- Recompiling Minitalk project..."
	@printf "\e[0m"

re : fclean libftclean echore all
