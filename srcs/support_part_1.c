/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_part_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:35:04 by tsimonis          #+#    #+#             */
/*   Updated: 2019/06/06 21:56:03 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_exit(int value, char *path)
{
	if (value == e_illegal_option)
		exit(ft_fprintf(2, "ls: illegal option -- %s\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", path));
	else if (value == e_malloc_error)
		exit(ft_fprintf(2, "malloc error\n"));
}

void	add_path(t_input *input, char *path)
{
	struct stat		buf;
	t_paths			*tmp;

	if (stat(path, &buf))
		ft_fprintf(2, "ls: %s: No such file or directory\n", path);
	else
	{
		if (input->paths->filepath)
		{
			if (!(tmp = (t_paths *)malloc(sizeof(*tmp))))
				error_exit(e_malloc_error, "");
			tmp->buf = buf;
			tmp->filepath = path;
			tmp->next = input->paths;
			input->paths = tmp;
		}
		else
		{
			input->paths->buf = buf;
			input->paths->filepath = path;
			input->paths->next = NULL;
		}
	}
}

void	reverse_paths_and_bufs(t_input *input)
{
	t_paths		*prev;
	t_paths		*curr;
	t_paths		*next;

	prev = NULL;
	curr = input->paths;
	while (curr->next)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr->next = prev;
	input->paths = curr;
}
