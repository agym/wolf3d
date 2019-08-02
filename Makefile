# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agym <agym@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 22:05:29 by agym              #+#    #+#              #
#    Updated: 2019/08/01 16:42:46 by agym             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FILES =  ./src/main.c gnl/get_next_line.c ./src/math.c ./src/free.c ./src/menue.c ./src/events.c ./src/ray_casting.c ./src/events1.c ./src/bresenham.c 
BINFILE =  main.o get_next_line.o  math.o free.o events.o ray_casting.o events1.o menue.o bresenham.o
FLAGS = -Wall -Wextra -Werror -c
LIB = -lmlx -framework OpenGL -framework  AppKit

all : $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) $(FILES)
	@gcc -o $(NAME) $(LIB) $(BINFILE)  -L libft/ -lft

clean :
	@rm -f $(BINFILE)
	@make -C  libft clean

fclean :
	@rm -rf $(NAME)
	@make -C libft fclean
	@rm -f $(BINFILE)

re : fclean all
