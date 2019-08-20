/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:38:09 by sghezn            #+#    #+#             */
/*   Updated: 2019/08/20 18:34:40 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** An auxillary function which returns 1
** if a directory passed as argument
** is not named "." or "..".
*/

int		ft_ok(t_file *dir)
{
	if (ft_strcmp(dir->name, ".") == 0)
		return (0);
	if (ft_strcmp(dir->name, "..") == 0)
		return (0);
	return (1);
}

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
** Printing a directory name before printing
** its contents, if necessary.
*/

void	ft_print_dir_name(char *path, int *first, int n)
{
	if (n != 0 && n != 1)
	{
		if (*first == 2)
		{
			*first = 1;
			ft_printf("%s:\n", path);
		}
		else
			ft_printf("\n%s:\n", path);
	}
}

/*
** Printing everything.
*/

void	ft_print_all(t_file *files, int flags, int first, int n)
{
	t_file	*file;

	if (!first && !(flags & 2))
		return ;
	while (files)
	{
		if (S_ISDIR(files->stats.st_mode) && (first || ft_ok(files)))
		{
			ft_print_dir_name(files->path, &first, n);
			file = ft_read_dir(files->path, flags);
			if (file)
			{
				ft_print_files(&file, flags);
				ft_print_all(file, flags, 0, -1);
				ft_free_files(&file);
			}
			if (errno == EACCES)
				ft_permission_error(files->path, flags, first, n);
		}
		files = files->next;
	}
}
