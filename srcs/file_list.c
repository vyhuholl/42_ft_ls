/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:29:57 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/11 23:50:54 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    *ft_get_path(char *name)
{

}

/*
** A function that creates a new file, given name, path and stat.
*/

t_file  *ft_create_new_file(char *name, char *path, t_stat stat)
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
    file->path = ft_get_path(file);
    file->next = NULL;
    return (file)
}

t_file	*ft_create_file_list(int argc, char **argv)
{
    
}
