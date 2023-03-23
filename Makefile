# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fl-hote <fl-hote@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 13:03:09 by reallaou          #+#    #+#              #
#    Updated: 2023/03/23 16:26:53 by fl-hote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
CFLAGS		:=	-Ofast
NAME		:=	cub3d
LDFLAGS		:=	-L./libft  -L./MLX42 -L/Users/$(USER)/.brew/opt/glfw/lib/
# LDLIBS		:=	-lft -lmlx42 -lglfw 
LDLIBS		:=	-lft -lmlx42 -lglfw -framework OpenGL -ldl -pthread -lm
SRCS		:=	$(wildcard src/*/*.c) src/main.c
OBJS		:=	$(SRCS:%.c=build/%.o)
RM			:=	rm -rf

all:		$(NAME)

debug:		CFLAGS += -gdwarf-4
debug:		$(NAME)

build/%.o:	%.c
			@mkdir -p build build/src build/src/error build/src/init\
					build/src/free build/src/parsing build/src/utils\
					build/src/render
			@$(CC) $(CFLAGS) -c $< -o $@


$(NAME):	$(OBJS)
			@$(MAKE) -C libft
			@$(MAKE) -C MLX42
			@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
			@echo 'build cub3d'

clean:
			@$(MAKE) clean -C libft
			@$(MAKE) clean -C MLX42
			@$(RM) build
			@echo 'clean'

fclean:		clean
			$(RM) $(NAME) libft/libft.a cub3d.dSYM valgrind-out.txt

re:			fclean all

redebug:	fclean debug

.PHONY:		all debug clean fclean re redebug
