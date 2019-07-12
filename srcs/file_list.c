/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:29:57 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/12 04:52:02 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** A function that creates a new file, given filename and stat.
*/

t_file  *ft_create_new_file(char *name, t_stat *stat)
{
    t_file  *file;

    if (!((file = (t_file*)malloc(sizeof(t_file) + 1))
    || (file->name = ft_strdup(name))))
        ft_raise_error(NULL, 2);
    file->mode = stat->st_mode;
    file->n_links = stat->st_nlink;
    file->user_id = stat->st_uid;
    file->group_id = stat->st_gid;
    file->size = stat->st_size;
    file->atime = stat->st_atime;
    file->mtime = stat->st_mtime;
    file->next = NULL;
    return (file);
}

/*
** A function that adds a file to the list
** or, in case list didn't exist, creates a new list.
*/

int     ft_add_new_file(char *name, t_file **list)
{
    t_stat  *stat;

    if (lstat(name, stat) == -1)
        return (-1);
    if (!*list)
        *list = ft_create_new_file(name, stat);
    else
    {
        while ((*list)->next)
            list = &((*list)->next);
        (*list)->next = ft_create_new_file(name, stat);
    }
    return (1);
}

/*
** A function that creates a file list from ls arguments.
*/

t_file	*ft_create_file_list(int argc, char **argv)
{
    t_file  *file_list;
    int     i;

    i = 1;
    file_list = NULL;
    while (i < argc && argv[i][0] == '-')
        i++;
    while (i < argc)
    {
        if (add_new_file(argv[i], "", file_list) == -1)
            ft_raise_error(argv[i], ERRNO);
        i++;
    }
    return (file_list);
}
