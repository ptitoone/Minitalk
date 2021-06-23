# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 11:35:52 by akotzky           #+#    #+#              #
#    Updated: 2021/06/23 12:52:25 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	server
NAME_CLI	=	client

LIBFT		=	libft.a

SRC_SRV		=	srcs/server.c
SRC_CLI		=	srcs/client.c
OBJ_SRV		=	$(SRC_SRV:.c=.o)
OBJ_CLI		=	$(SRC_CLI:.c=.o)

SRC_SRVB	=	srcs/server_bonus.c
SRC_CLIB	=	srcs/client_bonus.c
OBJ_SRVB	=	$(SRC_SRVB:.c=.o)
OBJ_CLIB	=	$(SRC_CLIB:.c=.o)

BONUS_MADE	=	$(wildcard .bonu*)

INCLS		=	-Iincls

CFLAGS		=	-Wall -Wextra -Werror 
CC			=	gcc

.PHONY : all bonus bonus_made clean fclean re info_re


all : bonus_made $(LIBFT) $(NAME) $(NAME_CLI)

bonus :
	@make -f Makefile_bonus bonus

bonus_made :
ifeq "$(BONUS_MADE)" ".bonus"
	@rm -rf server client .bonus
endif

$(NAME) : $(OBJ_SRV)
	@$(info - Linking Minitalk server file...)
	@$(CC) $(CFLAGS) $(OBJ_SRV) -L . -lft -o $(NAME)

$(NAME_CLI) : $(OBJ_CLI)
	@$(info - Linking Minitalk server file...)
	@$(CC) $(CFLAGS) $(OBJ_CLI) -L . -lft -o $(NAME_CLI)

$(LIBFT) :
	@make -C ./libft all
	@cp ./libft/$(LIBFT) .
	@cp ./libft/incls/libft.h ./incls
	@cp ./libft/incls/ft_printf.h ./incls 
	@cp ./libft/incls/get_next_line.h ./incls

%.o : %.c
	@$(info - Assembling Minitalk $< to $@ file...)
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

clean : libftclean
	@$(info - Cleaning Minitalk object files...)
	@rm -rf $(OBJ_SRV) $(OBJ_CLI) $(OBJ_SRVB) $(OBJ_CLIB)
	@make -C ./libft clean

fclean : clean libftfclean
	@$(info - Cleaning Minitalk header, binary and library files...)
	@rm -rf incls/libft.h incls/ft_printf.h incls/get_next_line.h $(NAME) $(NAME_CLI) $(LIBFT) $(BONUS_MADE)
	@$(info - Cleaning Libft library file...)
	@rm -rf libft/libft.a

info_re :
	@printf "\e[1;32m"
	@echo "\n- Recompiling Minitalk project..."
	@printf "\e[0m"

re : fclean info_re all
