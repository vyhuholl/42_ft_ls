/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:59:45 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 23:44:25 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        ft_compute_single_format(t_file *file, t_format *format)
{
    format->total += file->stat->st_blocks;
    format->nlink_len = ft_max(format->nlink_len, ft_nbrlen(file->stat->st_nlink));
    format->user_len = ft_max(format->user_len, (int)ft_strlen(file->username));
    format->group_len = ft_max(format->group_len, (int)ft_strlen(file->groupname));
    format->size_len = ft_max(format->size_len, ft_nbrlen((int)file->stat->st_size));
    if (ft_filetype(file) == 'b' || ft_filetype(file) == 'c')
    {
        format->major_len = ft_max(format->major_len, ft_nbrlen((int)major(file->stat->st_rdev) + 1));
        format->minor_len = ft_max(format->minor_len, ft_nbrlen((int)minor(file->stat->st_rdev) + 1));
    }
    format->name_len = ft_max(format->name_len, (int)ft_strlen(file->name));
}

t_format    *ft_compute_format(t_file *files)
{
    t_format    *format;
    t_file      *ptr;

    ptr = files;
    ft_memset(format, 0, sizeof(t_format));
    while (ptr)
    {
        ft_compute_single_format(ptr, format);
        ptr = ptr->next;
    }
    if (format->major_len != 0 || format->minor_len != 0)
        format->size_len = ft_max(format->size_len, format->major_len + format->minor_len + 2);
    return (format);
}

void        ft_show_file(t_file *file, t_flags *flags, t_format *format)
{
    if (flags->long_format == 1)
        ft_print_long(file, flags, format);
    else
        ft_printf("%s\n", file->name);
}

void        ft_show_files(t_file *files, t_flags *flags)
{
    t_format    *format;

    format = ft_compute_format(files);
    if (flags->long_format && files)
        ft_printf("total %d\n", format->total);
    while (files)
    {
        ft_show_file(file, flags, format);
        files = files->next;
    }
}

void        ft_show_dir(t_dir *dir, t_flags *flags)
{
    ft_printf("%s:\n", dir->name);
    ft_show_files(dir->files);
    ft_printf("\n");
}
