# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reallaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 13:06:50 by reallaou          #+#    #+#              #
#    Updated: 2023/03/01 13:07:05 by reallaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang 
CFLAGS = -Wall -Werror -Wextra -gdwarf-4 -I $(INCLUDES)
AR = ar -rcs
INCLUDES = libft.h
NAME = libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=build/%.o)

all: $(NAME)

build/%.o:	%.c
			@mkdir -p build
			@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
	@rm -rf build
	@echo 'clean libft'

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
