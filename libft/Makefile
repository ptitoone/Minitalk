# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 21:01:08 by akotzky           #+#    #+#              #
#    Updated: 2021/06/14 18:54:39 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a
SRCS	:=	$(shell echo srcs/*.c)
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror 
CC		=	gcc
INCLS	=	-Iincls

.PHONY : all clean fclean re
	
all : $(NAME)

$(NAME) : echobjs $(OBJS)
	@$(info - Archiving Libft object files...)
	@ar rcs $(NAME) $(OBJS)

echobjs :
	@$(info - Assembling Libft object files...)

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

clean :
	@$(info - Cleaning Libft object files...)
	@rm -rf $(OBJS)

fclean : clean 
	@$(info - Cleaning Libft library file...)
	@rm -rf $(NAME)

re : fclean all
	@$(info - Rebuilding Libft library project...)

