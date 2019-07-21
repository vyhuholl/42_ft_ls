/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 07:58:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/21 19:47:46 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** A function for error handling.
** It prints usage in case of
** an invalid option and
** error message otherwise.
*/

void	ft_error(char c, int error)
{
	if (error == 0)
	{
		ft_printf("ft_ls: illegal option -- %c\n", c);
		ft_putstr("usage: ft_ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] ");
		ft_printf("[file ...]\n");
	}
	else
		ft_putstr((strerror(errno)));
	exit(EXIT_FAILURE);
}

/*
** An auxillary function that returns 1 if given
** a t_file structure with name = "", path = "./"
** and next = NULL and 0 otherwise.
*/

int		ft_is_first(t_file *files)
{
	if (ft_strcmp(files->name, "") == 0 &&
	ft_strcmp(files->path, "./") == 0 &&
	!(files->next))
		return (1);
	return (0);
}

/*
** A function that reads a directory
** and returns a t_file structrure
** with directory contents.
*/

t_file	*ft_read_dir(char *path, int flags)
{
	t_dirent	*entry;
	t_file		*files;
	DIR			*dir;

	files = NULL;
	dir = opendir(path);
	if (flags & 128)
		ft_add_file(path, "", &files);
	else
		while ((entry = readdir(dir)))
			if (entry->d_name[0] != '.' || (flags & 4) || (flags & 64))
				ft_add_file(path, entry->d_name, &files);
	closedir(dir);
	return (files);
}

/*
** A function that frees a t_file structure.
*/

void	ft_free_files(t_file **files)
{
	while (*files)
	{
		free((*files)->name);
		free((*files)->path);
		free(*files);
		*files = (*files)->next;
	}
}

int		main(int argc, char **argv)
{
	t_file	*file_list;
	int		file_index;
	int		flags;

	flags = 0;
	file_index = ft_parse_options(argc, argv, &flags);
	ft_printf("flags: %d\n", flags);
	if (file_index == -1)
		return (-1);
	argc -= file_index;
	argv += file_index;
	file_list = ft_file_list(argc, argv, flags);
	ft_print_all(file_list, flags);
	ft_free_files(&file_list);
	return (0);
}
