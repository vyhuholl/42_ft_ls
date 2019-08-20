# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 17:02:44 by tsimonis          #+#    #+#              #
#    Updated: 2019/08/20 16:01:30 by sghezn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAG = -Wall -Wextra -Werror
SRC = main.c compare.c error.c long_format.c parse_input.c print.c sort.c short_format.c
OBJ = main.o compare.o error.o long_format.o parse_input.o print.o sort.o short_format.o

all: $(NAME)

$(NAME): lib $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) -L libft -lft

$(OBJ):
	gcc $(FLAG) -c $(SRC) -I ft_ls.h -I libft/includes/libft.h

lib:
	make -C libft

clean:
	make -C libft clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(NAME)

re: fclean all
