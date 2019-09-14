/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:54:08 by sghezn            #+#    #+#             */
/*   Updated: 2019/09/14 13:07:38 by sghezn           ###   ########.fr       */
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

void	ft_reverse_list(t_file **file)
{
	t_file *current;
	t_file *next;
	t_file *previous;

	previous = *file;
	if ((current = previous->next) == NULL)
		return ;
	previous->next = NULL;
	while (current->next)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	current->next = previous;
	*file = current;
}


/*
** A function which sorts a t_file structure according to flags.
*/

void	ft_sort_files(t_file **files, int flags)
{
	*files = ft_sort_list(*files, &ft_namecmp);
	if ((flags & 16))
	{
		if ((flags & 32))
			*files = ft_sort_list(*files, &ft_atimecmp);
		else
			*files = ft_sort_list(*files, &ft_mtimecmp);
	}
	if ((flags & 8))
		ft_reverse_list(files);
}

/*
** A function which sorts a 2D char
** array of filenames alphabetically.
*/

void	ft_sort_names(char **names, int size)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i - 1;
		temp = names[i];
		while (j >= 0 && ft_strcmp(names[j], temp) > 0)
		{
			names[j + 1] = names[j];
			j--;
		}
		names[j + 1] = temp;
		i++;
	}
}
