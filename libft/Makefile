# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agym <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/31 14:48:23 by agym              #+#    #+#              #
#    Updated: 2019/04/09 17:03:00 by agym             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OUT = *.o

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c *.c -I $(INCLUDES)
	@ar rc $(NAME) $(OUT)
	@ranlib $(NAME)

clean:
	@rm -f $(OUT)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
