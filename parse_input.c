/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:04:21 by sghezn            #+#    #+#             */
/*   Updated: 2019/09/14 12:23:24 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** A function which, for every option with
** index n, inverts n-th bit in flags.
** (https://ru.wikipedia.org/wiki/Операторы_в_C_и_C%2B%2B)
** By default, all bits are set to 0.
** In case of the invalid option,
** error is raised and -1 is returned.
*/

void	ft_parse_option(char *option, int *flags)
{
	int index;
	int i;

	i = 1;
	while (option[i])
	{
		index = ft_strchr_index("lRartufd1", option[i]);
		if (index == -1)
			ft_options_error(option[i]);
		*flags |= (1 << index);
		i++;
	}
}

/*
** A function which parses all options
** and returns index of the first file in argv.
** In case of invalid option, -1 is returned.
*/

int		ft_parse_options(int argc, char **argv, int *flags)
{
	int i;

	*flags = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1])
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_fts_error();
			return (-1);
		}
		if (argv[i][1] == '-')
			return (i + 1);
		ft_parse_option(argv[i], flags);
		i++;
	}
	return (i);
}

/*
** A function which allocates and returns
** full path to the file.
*/

char	*ft_get_path(char *path, char *name)
{
	size_t	len;
	char	*temp;

	if (!path)
		return (ft_strdup(name));
	temp = 0;
	if ((len = ft_strlen(path)))
	{
		path = ft_strjoin(path, path[len - 1] != '/' ? "/" : "");
		temp = path;
	}
	path = ft_strjoin(path, name);
	if (temp)
		free(temp);
	if (!path)
		ft_memory_error();
	return (path);
}

/*
** A function which adds a file to an existing list
** or creates a new list if it doesn't exist.
*/

void	ft_add_file(char *path, char *name, t_file **file_list)
{
	t_file	*file;
	t_stat	stat;

	path = ft_get_path(path, name);
	file = (t_file*)ft_memalloc(sizeof(t_file));
	file->name = ft_strdup(name);
	file->path = path;
	if (!file || !file->name || !file->path)
		ft_memory_error();
	if (lstat(path, &stat) == -1)
	{
		if (errno == ENOMEM)
			ft_memory_error();
		if (errno == EACCES)
			ft_permission_error(name);
	}
	file->stats = stat;
	if (!*file_list)
		*file_list = file;
	else
	{
		while ((*file_list)->next)
			file_list = &((*file_list)->next);
		(*file_list)->next = file;
	}
}

/*
** A function which creates a linked structure
** t_file from an array of filenames.
*/

t_file	*ft_file_list(int argc, char **file_names, int flags)
{
	t_file	*file_list;
	t_list	*not_found;
	t_stat	stat;
	int		i;

	file_list = NULL;
	not_found = NULL;
	if (!argc)
		ft_add_file(".", "", &file_list);
	if (!(flags & 64) && file_names && argc)
		ft_sort_names(file_names, argc);
	i = -1;
	while (++i < argc)
	{
		if (ft_strlen(file_names[i]) == 0)
			ft_fts_error();
		if (lstat(file_names[i], &stat) == -1 && errno == ENOENT)
			not_found = ft_lstappend(not_found, file_names[i]);
		else
			ft_add_file("", file_names[i], &file_list);
	}
	if (not_found)
		ft_not_found_error(not_found);
	return (file_list);
}
