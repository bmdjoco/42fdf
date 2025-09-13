# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 11:40:39 by bdjoco            #+#    #+#              #
#    Updated: 2025/06/19 17:48:11 by bdjoco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/print_type.c \
	src/print_type_bis.c \
	src/def_type.c \
	src/def_type_bis.c \
	src/ft_printf.c \
	lib/ft_putchar_fd.c \
	lib/ft_putstr_fd.c \
	lib/ft_strlen.c \
	lib/ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

BOLD = \e[1m
GREEN = \e[32m
PURPLE = \e[35m
RESET = \e[0m

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(BOLD)$(PURPLE)$(NAME)$(RESET) $(GREEN)est compilé$(RESET)​ 🔰​"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)
	@echo "🚮 $(GREEN)Nettoyage des$(RESET) $(BOLD)fichiers source de ft_printf$(RESET) $(GREEN)terminé$(RESET) 🚮"

fclean : clean
	@$(RM) $(NAME)
	@echo "🚮 $(GREEN)Nettoyage de$(RESET) $(BOLD)libftprintf.a$(RESET) $(GREEN)terminé$(RESET) 🚮"

re : fclean all

.PHONY: all clean fclean re
