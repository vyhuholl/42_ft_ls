# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 17:02:44 by tsimonis          #+#    #+#              #
#    Updated: 2019/07/14 18:00:10 by sghezn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re rebuild_lib re1 fclean1

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

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(addprefix -I,$(INCLUDES)) -L./libft -lft -o $@

libft/libft.a:
	$(MAKE) -C libft

$(OBJECTS): %.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(addprefix -I,$(INCLUDES))

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebuild_lib:
	$(MAKE) re -C libft

re1: rebuild_lib fclean all

fclean1: fclean
	$(MAKE) fclean -C libft
