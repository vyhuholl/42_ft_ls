/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:25:57 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 13:32:27 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_time_a_diff(char *file_1, char *file_2)
{
    t_stat  stat_1;
    t_stat  stat_2;

    lstat(file_1, &stat_1);
    lstat(file_2, &stat_2);
    if (stat_1.st_atimespec.tv_sec <= stat_2.st_atimespec.tv_sec)
        return (-1);
    else
        return (1);
}

int     ft_time_m_diff(char *file_1, char *file_2)
{
    t_stat  stat_1;
    t_stat  stat_2;

    lstat(file_1, &stat_1);
    lstat(file_2, &stat_2);
    if (stat_1.st_mtimespec.tv_sec <= stat_2.st_mtimespec.tv_sec)
        return (-1);
    else
        return (1);
}

void    ft_sort_list(t_list *list, int (*cmp)(char*, char*))
{
    t_list  *temp;
    char    *swap;

    temp = list;
    while (list->next)
    {
        if (((*cmp)(list->data, list->next->data)) > 0)
        {
            swap = list->data;
            list->data = list->next->data;
            list->next->data = swap;
            list = temp;
        }
        else
            list = list->next;
    }
    list = temp;
}

void    ft_sort(t_options *options)
{
    if (options->flags->time_a == 1)
    {
        ft_sort_list(options->files, ft_time_a_diff());
        ft_sort_list(options->dirs, ft_time_a_diff());
    }
    else if (options->flags->time_m == 1)
    {
        ft_sort_list(options->files, ft_time_m_diff());
        ft_sort_list(options->dirs, ft_time_m_diff());
    }
    else if (options->flags->unsorted != 1)
    {
        ft_sort_list(options->files, ft_strcmp());
        ft_sort_list(options->dirs, ft_strcmp());
    }
    if (options->flags->reversed == 1)
    {
        ft_lstreverse(options->files);
	    ft_lstreverse(options->dirs);
    }
}
