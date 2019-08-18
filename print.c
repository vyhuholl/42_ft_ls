/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:38:09 by sghezn            #+#    #+#             */
/*   Updated: 2019/08/18 13:56:52 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** A function that prints last access/modification
** time of a file, used for long format.
*/

void	ft_print_time(t_file *file, int flags)
{
	if (flags & 32)
		ft_printf(" %.12s", ctime(&(file->stats.st_atime)) + 4);
	else
		ft_printf(" %.12s", ctime(&(file->stats.st_mtime)) + 4);
}

/*
** A function that sorts and prints files accordingly.
*/

void	ft_print_files(t_file **files, int flags)
{
	if (!(flags & 64))
		ft_sort_files(files, flags);
	if (!(flags & 1))
		ft_print_short(*files, flags);
	else
		ft_print_long(*files, flags);
}

/*
** Printing everything.
*/

void	ft_print_all(t_file *file_list, int flags, int first)
{
	t_file	*files;

	if (!first && !(flags & 2))
		return ;
	while (file_list)
	{
		if (S_ISDIR(file_list->stats.st_mode) && (first ||
			(ft_strcmp(file_list->name, ".") != 0 &&
			ft_strcmp(file_list->name, "..") != 0)))
		{
			if (!first)
				ft_printf("\n%s:\n", file_list->path);
			files = ft_read_dir(file_list->path, flags);
			if (files)
			{
				ft_print_files(&files, flags);
				ft_print_all(files, flags, 0);
				ft_free_files(&files);
			}
		}
		file_list = file_list->next;
	}
}
