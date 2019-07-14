/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:59:45 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 20:26:08 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_show_file(t_file *file, t_flags *flags)
{
    if (flags->long_format == 1)
        ft_show_long_format(file, flags);
    else
        ft_printf("%s\n", file->name);   
}

void    ft_show_files(t_file *files, t_flags *flags)
{
    while (files)
    {
        ft_show_file(file, flags);
        files = files->next;
    }
}

void    ft_show_dir(t_dir *dir, t_flags *flags)
{
    ft_printf("%s:\n", dir->name);
    ft_show_files(dir->files);
    ft_printf("\n");
}
