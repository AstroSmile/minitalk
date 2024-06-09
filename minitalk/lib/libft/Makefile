# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 18:08:21 by ana-maro          #+#    #+#              #
#    Updated: 2024/06/09 17:47:27 by ana-maro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -g -Wall -Wextra -Werror
CC = gcc
CLEAN = rm -Rf
SRC = ft_strlen.c \
	  		ft_memmove.c \
			ft_memcpy.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_bzero.c \
			ft_memset.c \
			ft_isprint.c \
			ft_isascii.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strrchr.c \
			ft_memchr.c \
			ft_split.c \

SRCB = ft_lstnew_bonus.c \
	   	ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
PF_SRC = ../printf/ft_printf_utils.c \
				../printf/ft_printf.c

GNL_SRC = ../gnl/get_next_line.c \
				../gnl/get_next_line_utils.c
				
OBJ = $(SRC:.c=.o)
BOBJ = $(SRCB:.c=.o)
PF_OBJECT = $(PF_SRC:.c=.o)
GNL_OBJECT = $(GNL_SRC:.C=.O)

all: $(NAME) 

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(PF_OBJECT) $(GNL_OBJECT)
	@echo "\033[0;32mCreando libreria libft.a\033[0m"

bonus: $(BOBJ)
	@ar rcs $(NAME) $(BOBJ)
	@echo "Incluimos bonus en la libreria libft.a"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(CLEAN) ./*.o

fclean:
	@$(CLEAN) ./*.o
	@$(CLEAN) ./*.a

re: fclean all
i.PHONY: all clean fclean re bonus
