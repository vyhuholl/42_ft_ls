/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:54:08 by sghezn            #+#    #+#             */
/*   Updated: 2019/08/10 22:24:17 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** An auxillary function swapping two items in a t_file structure.
*/

t_file	*ft_files_swap(t_file *file_1, t_file *file_2)
{
	file_1->next = file_2->next;
	file_2->next = file_1;
	return (file_2);
}

/*
** A function which sorts a t_file structure according to a function.
*/

t_file	*ft_sort_list(t_file *list, int (*cmp)(t_file*, t_file*))
{
	if (!list)
		return (NULL);
	if (list->next && (*cmp)(list, list->next) > 0)
		list = ft_files_swap(list, list->next);
	list->next = ft_sort_list(list->next, cmp);
	if (list->next && (*cmp)(list, list->next) > 0)
	{
		list = ft_files_swap(list, list->next);
		list->next = ft_sort_list(list->next, cmp);
	}
	return (list);
}

/*
** A function which reverses a t_file structure.
*/

t_file	*ft_reverse_list(t_file *list)
{
	t_file *prev;
	t_file *curr;
	t_file *next;

	prev = NULL;
	curr = list;
	next = list->next;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return (prev);
}

/*
** A function which sorts a t_file structure according to flags.
*/

void	ft_sort_files(t_file **files, int flags)
{
	*files = ft_sort_list(*files, &ft_namecmp);
	if ((flags & 16))
		*files = ft_sort_list(*files, &ft_mtimecmp);
	if ((flags & 32))
		*files = ft_sort_list(*files, &ft_atimecmp);
	if ((flags & 8))
		*files = ft_reverse_list(*files);
}

/*
** A function which sorts a 2D char
** array of filenames alphabetically.
*/

void	ft_sort_names(char **names)
{
	char	*temp;
	int		i;

	i = 0;
	while (names[i + 1])
	{
		if (ft_strcmp(names[i], names[i + 1]) > 0)
		{
			temp = names[i];
			names[i] = names[i + 1];
			names[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
