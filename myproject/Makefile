# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agym <agym@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 18:32:31 by agym              #+#    #+#              #
#    Updated: 2019/07/31 17:16:01 by agym             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = main.c textur.c points_lignes.c error_test.c
# BIN = main.o textur.o points_lignes.o
FLAG = -Wall -Wextra -Werror

game:
	 @gcc $(FLAG) $(FILE) -o main -I include -L lib -l SDL2-2.0.0
