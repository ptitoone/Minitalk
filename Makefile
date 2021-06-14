# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 11:35:52 by akotzky           #+#    #+#              #
#    Updated: 2021/06/14 18:52:47 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRV	=	server
NAME_CLI	=	client
NAME_SRVB	=	server_bonus
NAME_CLIB	=	client_bonus

LIBFT		=	libft.a

SRC_SRV		=	srcs/server.c
SRC_CLI		=	srcs/client.c
OBJ_SRV		=	$(SRC_SRV:.c=.o)
OBJ_CLI		=	$(SRC_CLI:.c=.o)

SRC_SRVB	=	srcs/server_bonus.c
SRC_CLIB	=	srcs/client_bonus.c
OBJ_SRVB	=	$(SRC_SRVB:.c=.o)
OBJ_CLIB	=	$(SRC_CLIB:.c=.o)


INCLS		=	-Iincls

CFLAGS		=	-Wall -Wextra -Werror 
CC			=	gcc

.PHONY	:	all bonus clean fclean re

bonus : $(LIBFT) $(NAME_SRVB) $(NAME_CLIB)

all : $(LIBFT) $(NAME_SRV) $(NAME_CLI)

$(NAME_SRV) : $(OBJ_SRV)
	@$(info - Assembling Minitalk object files...)
	@$(info - Linking Minitalk server files...)
	@$(CC) $(CFLAGS) $(OBJ_SRV) -L . -lft -o $(NAME_SRV)

$(NAME_CLI) : $(OBJ_CLI)
	@$(info - Assembling Minitalk object files...)
	@$(info - Linking Minitalk server files...")
	@$(CC) $(CFLAGS) $(OBJ_CLI) -L . -lft -o $(NAME_CLI)

$(NAME_SRVB) : $(OBJ_SRVB)
	@$(info - Linking Minitalk client bonus files...)
	@$(CC) $(CFLAGS) $(OBJ_SRVB) -L . -lft -o $(NAME_SRV)

$(NAME_CLIB) : $(OBJ_CLIB)
	@$(info - Linking Minitalk client bonus files...)
	@$(CC) $(CFLAGS) $(OBJ_CLIB) -L . -lft -o $(NAME_CLI)

$(LIBFT) :
	@make -C ./libft all
	@cp ./libft/$(LIBFT) .
	@cp ./libft/incls/libft.h ./incls
	@cp ./libft/incls/ft_printf.h ./incls 
	@cp ./libft/incls/get_next_line.h ./incls

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

clean :
	@$(info - Cleaning Minitalk object files...)
	@rm -rf $(OBJ_SRV) $(OBJ_CLI) $(OBJ_SRVB) $(OBJ_CLIB)

fclean : clean
	@$(info - Cleaning Minitalk header, binary and library files...)
	@rm -rf incls/libft.h incls/ft_printf.h incls/get_next_line.h $(NAME_SRV) $(NAME_CLI) $(NAME_SRVB) $(NAME_CLIB) $(LIBFT)
	@make -C ./libft clean

libftclean : 
	@make -C ./libft fclean

echore :
	@printf "\e[1;32m"
	@echo "\n- Recompiling Minitalk project..."
	@printf "\e[0m"

re : fclean libftclean echore all
