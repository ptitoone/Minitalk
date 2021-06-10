# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 21:01:08 by akotzky           #+#    #+#              #
#    Updated: 2021/06/10 22:45:12 by akotzky          ###   ########.fr        #
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
	@echo "- Archiving Libft object files..."
	@ar rcs $(NAME) $(OBJS)

echobjs :
	@echo "- Assembling Libft object files..."

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

clean :
	@echo "- Cleaning Libft object files..."
	@rm -rf $(OBJS)

fclean : clean 
	@echo "- Cleaning Libft library file..."
	@rm -rf $(NAME)

re : fclean all
	@echo "- Rebuilding Libft library project..."

