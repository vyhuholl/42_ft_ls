/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:35:11 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/15 03:09:31 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_free_list(t_list *list)
{
    t_list  *ptr;

    while (list)
    {
        ptr = list->next;
        ft_memdel((void**)&list->content);
        ft_memdel((void**)&list);
        list = ptr;
    }
}

void    ft_free_file(t_file *file)
{
    t_file  *files;
    t_file  *next;

    files = file;
    while (files)
    {
        next = files->next;
        ft_memdel((void**)&files->name);
        ft_memdel((void**)&files->path);
        ft_memdel((void**)&files->username);
        ft_memdel((void**)&files->groupname);
        ft_memdel((void**)&files->stats);
        ft_memdel((void**)&files);
        files = next;
    }
    file = NULL;
}

void    ft_free_dir(t_dir *dir)
{
    t_dir   *temp;
    t_file  *files;

    ft_memdel((void**)&dir->name);
    files = dir->files;
    ft_free_file(files);
    temp = dir->next;
    ft_memdel((void**)&dir);
    dir = temp;
}
