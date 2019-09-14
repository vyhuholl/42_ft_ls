/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 07:58:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/09/14 13:35:56 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** A function that reads a directory
** and returns a t_file structrure
** with directory contents.
*/

t_file	*ft_read_dir(char *name, char *path, int flags)
{
	t_dirent	*entry;
	t_file		*files;
	DIR			*dir;

	files = NULL;
	dir = opendir(path);
	if (!dir && errno == EACCES)
	{
		ft_permission_error(name);
		return (NULL);
	}
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
** An auxullary function which adds a new link
** with the content value to a linked list lst
** (which can be empty).
*/

t_list	*ft_lstappend(t_list *lst, void const *content)
{
	t_list	*new;

	new = ft_lstnew(content, sizeof(content));
	if (!new)
		ft_memory_error();
	if (!lst)
		return (new);
	lst->next = new;
	return (lst);
}

/*
** A function that frees a t_file structure.
*/

void	ft_free_files(t_file *files)
{
	t_file	*ptr;

	while (files)
	{
		ptr = files->next;
		free(files->name);
		free(files->path);
		ft_memdel((void**)&files);
		files = ptr;
	}
}

t_file	*ft_dir_list(int argc, char **file_names)
{
	t_file	*dir_list;
	t_stat	stat;
	int		i;

	dir_list = NULL;
	if (!argc)
		ft_add_file("", ".", &dir_list);
	i = -1;
	while (++i < argc)
	{
		if (ft_strlen(file_names[i]) == 0)
			ft_fts_error();
		lstat(file_names[i], &stat);
		if (S_ISDIR(stat.st_mode))
			ft_add_file("", file_names[i], &dir_list);
	}
	return (dir_list);
}

int		main(int argc, char **argv)
{
	t_file	*file_list;
	t_file	*dir_list;
	int		file_index;
	int		flags;

	file_index = ft_parse_options(argc, argv, &flags);
	argc -= file_index;
	argv += file_index;
	file_list = ft_file_list(argc, argv, flags);
	dir_list = ft_dir_list(argc, argv);
	if (file_list)
	{
		ft_print_files(&file_list, flags);
		ft_putchar('\n');
	}
	if (!(flags & 64))
		ft_sort_files(&dir_list, flags);
	ft_print_all(dir_list, flags, 2, argc);
	ft_free_files(file_list);
	ft_free_files(dir_list);
	return (0);
}
