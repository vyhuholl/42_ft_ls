/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 07:58:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/08/20 18:29:44 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	if (!dir)
		return (NULL);
	if (flags & 128)
		ft_add_file(path, "", &files, flags);
	else
		while ((entry = readdir(dir)))
			if (entry->d_name[0] != '.' || (flags & 4) || (flags & 64))
				ft_add_file(path, entry->d_name, &files, flags);
	closedir(dir);
	return (files);
}

/*
** An auxullary function which adds a new link
** with the content value to a linked list lst
** (which can be empty).
*/

t_list	*ft_lstappend(t_list *lst, void const *content, int flags)
{
	t_list	*new;

	new = ft_lstnew(content, sizeof(content));
	if (!new)
	{
		ft_memory_error(flags);
		return (NULL);
	}
	if (!lst)
		return (new);
	lst->next = new;
	return (lst);
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
	if (ft_strcmp(argv[argc - 1], "2>&1") == 0)
	{
		argc -= 1;
		flags = 512;
	}
	file_index = ft_parse_options(argc, argv, &flags);
	argc -= file_index;
	argv += file_index;
	file_list = ft_file_list(argc, argv, flags);
	ft_print_all(file_list, flags, 2, argc);
	ft_free_files(&file_list);
	return (0);
}
