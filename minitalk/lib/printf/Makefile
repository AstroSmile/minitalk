# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:35:37 by ana-maro          #+#    #+#              #
#    Updated: 2023/11/06 22:49:54 by ana-maro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
CLEAN = rm -Rf
SRC = ft_printf.c \
	  		ft_printf_utils.c \
					
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "creando carpetas"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "compilando"
clean:
	@$(CLEAN) ./*.o
	@echo "limpiando"
fclean:
	@$(CLEAN) ./*.o
	@$(CLEAN) ./*.a
	@echo "limpieza profunda"
re: fclean all
.PHONY: all clean fclean re
