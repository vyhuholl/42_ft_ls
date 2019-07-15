/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:47:15 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/15 03:16:15 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_print_time(time_t *time)
{
    char    *time_str;

    time_str = ctime(time) + 4;
    ft_printf((" %.12s ", time_str));
}

void    ft_printmod(t_file *file)
{
    ft_putchar(ft_filetype(file));
    ft_putchar((file->stats->st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar((file->stats->st_mode & S_IWUSR) ? 'w' : '-');
    if (file->stats->st_mode & S_ISUID)
        ft_putchar((file->stats->st_mode & S_IXUSR) ? 's' : 'S');
    else
        ft_putchar((file->stats->st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar((file->stats->st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar((file->stats->st_mode & S_IWGRP) ? 'w' : '-');
    if (file->stats->st_mode & S_ISGID)
        ft_putchar((file->stats->st_mode & S_IXGRP) ? 's' : 'S');
    else
        ft_putchar((file->stats->st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar((file->stats->st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar((file->stats->st_mode & S_IWOTH) ? 'w' : '-');
    if (file->stats->st_mode & S_ISVTX)
        ft_putchar((file->stats->st_mode & S_IXOTH) ? 's' : 'S');
    else
        ft_putchar((file->stats->st_mode & S_IXUSR) ? 'x' : '-');
}

void    ft_print_long(t_file *file, t_flags *flags, t_format *format)
{
    char    link[256];
    ssize_t ret;

    ft_printmod(file);
    ft_printf("%*d %-*s %-*s ", format->nlink_len + 1,
    file->stats->st.nlink, format->user_len + 1,
    file->username, format->group_len + 1, file->groupname);
    if (!(S_ISBLK(file->stats->st_mode) || S_ISCHR(file->stats->st_mode)))
        ft_printf("%*d ", format->size_len, file->stats->st_size);
    else
        ft_printf("%*d, %*d ", format->major_len,
        (int)major(file->stats->st_rdev), format->minor_len,
        (int)minor(file->stats->st_rdev));
    ft_print_time(file->stats->st_mtime);
    if (S_ISLNK(file->stats->st_mode))
    {
        ret = readlink(file->path, link, 256);
        link[ret] = '\0';
        ft_printf("%s -> %s\n", file->name, link);
    }
    else
        ft_printf("%s\n", file->name);
}
