/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:59:45 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/15 04:32:37 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        ft_compute_single_len(t_file *file, t_len *len)
{
    len->total += file->stats.st_blocks;
    len->nlink_len = ft_max(len->nlink_len, ft_nbrlen(file->stats.st_nlink));
    len->user_len = ft_max(len->user_len, (int)ft_strlen(file->username));
    len->group_len = ft_max(len->group_len, (int)ft_strlen(file->groupname));
    len->size_len = ft_max(len->size_len, ft_nbrlen((int)file->stats.st_size));
    if (ft_filetype(file) == 'b' || ft_filetype(file) == 'c')
    {
        len->major_len = ft_max(len->major_len, ft_nbrlen((int)major(file->stats.st_rdev) + 1));
        len->minor_len = ft_max(len->minor_len, ft_nbrlen((int)minor(file->stats.st_rdev) + 1));
    }
    len->name_len = ft_max(len->name_len, (int)ft_strlen(file->name));
}

t_len    *ft_compute_len(t_file *files)
{
    t_len   *len;
    t_file  *ptr;

    ptr = files;
    len = (t_len*)malloc(sizeof(t_len) + 1);
    ft_memset(len, 0, sizeof(t_len));
    while (ptr)
    {
        ft_compute_single_len(ptr, len);
        ptr = ptr->next;
    }
    if (len->major_len != 0 || len->minor_len != 0)
        len->size_len = ft_max(len->size_len, len->major_len + len->minor_len + 2);
    return (len);
}

void        ft_show_file(t_file *file, t_flags *flags, t_len *len)
{
    if (flags->long_format == 1)
        ft_print_long(file, flags, len);
    else
        ft_printf("%s\n", file->name);
}

void        ft_show_files(t_file *files, t_flags *flags)
{
    t_len    *len;

    len = ft_compute_len(files);
    if (flags->long_format && files)
        ft_printf("total %d\n", len->total);
    while (files)
    {
        ft_show_file(files, flags, len);
        files = files->next;
    }
}

void        ft_show_dir(t_dir *dir, t_flags *flags)
{
    ft_printf("%s:\n", dir->name);
    ft_show_files(dir->files, flags);
    ft_printf("\n");
}
