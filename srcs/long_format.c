/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:47:15 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 21:53:06 by sghezn           ###   ########.fr       */
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
