/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:14:01 by tsimonis          #+#    #+#             */
/*   Updated: 2019/06/07 03:37:21 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		struct_init(t_input **input)
{
	int		i;

	if (!(*input = (t_input *)malloc(sizeof(**input))))
		error_exit(e_malloc_error, "");
	i = 0;
	while (i < NUM_FLAGS)
		(*input)->flags[i++] = 0;
	if (!((*input)->paths = (t_paths *)malloc(sizeof(t_paths))))
		error_exit(e_malloc_error, "");
	(*input)->paths->filepath = NULL;
}

int			fill_flags(t_input *input, int argc, char **argv)
{
	int			num_arg;
	int			num_symbol;
	int			tmp;

	num_arg = 1;
	while (num_arg < argc && argv[num_arg][0] == '-')
	{
		num_symbol = 1;
		if (!(argv[num_arg][num_symbol]))
			break ;
		while (argv[num_arg][num_symbol] &&
		(tmp = ft_strchr_index(ALL_FLAGS, argv[num_arg][num_symbol])) != -1)
		{
			input->flags[tmp] = 1;
			num_symbol++;
		}
		if (argv[num_arg][num_symbol])
			error_exit(e_illegal_option, &(argv[num_arg][num_symbol]));
		num_arg++;
	}
	return (num_arg);
}

t_input		*parse_input(int argc, char **argv)
{
	int			num_arg;
	t_input		*input;

	struct_init(&input);
	if (argc == 1)
		return (input);
	if ((num_arg = fill_flags(input, argc, argv)) == argc)
		add_path(input, ".");
	while (num_arg < argc)
	{
		add_path(input, argv[num_arg]);
		num_arg++;
	}
	reverse_paths_and_bufs(input);
	return (input);
}