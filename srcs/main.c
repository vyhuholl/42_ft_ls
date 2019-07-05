/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:48:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/06/07 04:56:24 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// void	get_files_in_dir()
// {
// 	;
// }

// void	sort_files_in_dir()
// {
// 	;
// }

int		main(int argc, char **argv)
{
	t_input		*input;

	input = parse_input(argc, argv);
	if (input->flags[1]) // R
	{
		;
	}
	print_l_flag(input->paths->filepath, input->paths->buf);
	return (0);
}