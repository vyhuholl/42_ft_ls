/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:15:45 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 16:28:38 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_print_files(t_list *files_list, t_flags *flags)
{
    t_file  *files;
    char    *path;

    path = ft_strdup("/");
    files = NULL;
    while (files_list)
    {
        ft_add_file(files, files_list->data, path);
        files_list = files_list->next;
    }
    ft_sort_filelist(files, flags);
}

void	ft_print_all(t_options *options)
{
    t_list  *ptr;

	ft_print_files(options->files, options->flags);
    ptr = options->dirs;
    while (ptr)
    {
        ft_print_dir(ptr->content, options->flags);
        ptr = ptr->next;
    }
}
