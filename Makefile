# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 17:02:44 by tsimonis          #+#    #+#              #
#    Updated: 2019/07/15 06:31:12 by sghezn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

INCLUDES := ./includes \
			./libft/includes

CC = clang
FLAGS := -Wall -Werror -Wextra -g
VPATH := . srcs

SRCS =	main.c \
		errors.c \
		parse_options.c \
		file_getters.c \
		print.c \
		free.c \
		sort.c \
		sort_files.c \
		show.c \
		long_format.c \
		auxillary.c \

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(addprefix -I,$(INCLUDES)) -L./libft -lft -o $@

libft/libft.a:
	$(MAKE) -C libft

$(OBJECTS): %.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(addprefix -I,$(INCLUDES))

clean:
	/bin/rm -rf $(OBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
