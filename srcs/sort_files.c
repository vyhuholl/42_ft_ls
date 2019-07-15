/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:25:17 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/15 04:29:58 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_swap_files(t_file *file_1, t_file *file_2)
{
    t_file  *temp;

    temp = file_1;
    file_1 = file_2;
    file_2 = temp;
}

void    ft_sort_files(t_file *files, int (*cmp)(const char*, const char*))
{
    t_file  *temp;

    temp = files;
    while (files->next)
    {
        if (((*cmp)(files->name, files->next->name)) > 0)
        {
            ft_swap_files(files, files->next);
            files = temp;
        }
        else
            files = files->next;
    }
    files = temp;
}

void    ft_reverse_files(t_file *files)
{
    t_file  *curr;
    t_file  *next;
    t_file  *prev;

    prev = NULL;
    curr = files;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    files = prev;
}

void    ft_sort_filelist(t_file *files_list, t_flags *flags)
{
    if (flags->time_m == 1)
        ft_sort_files(files_list, &ft_time_m_diff);
    else
        ft_sort_files(files_list, &ft_strcmp);
    if (flags->reversed == 1)
        ft_reverse_files(files_list);
}
