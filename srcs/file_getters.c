/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:11:49 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 15:00:53 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    *ft_username(uid_t uid)
{
    
}

char    *ft_groupname(gid_t gid)
{
    
}

void    ft_add_file(t_file *files, char *name, char *path)
{
    t_file  *ptr;
    t_file  *file;
    t_stat  stat;

    file = (t_file*)malloc(sizeof(t_file) + 1);
    file->name = ft_strdup(name);
    file->path = ft_strjoin(path, name);
    lstat(name, stat)
    file->stat = stat;
}

int     ft_is_file_or_dir(char *filename)
{
    t_stat  stat;
    char    link[256];
    ssize_t ret;

    lstat(filename, &stat);
    if (S_ISREG(stat.st_mode))
        return (1);
    else if (S_ISDIR(stat.st_mode))
        return (2);
    else if (S_ISLNK(stat.st_mode))
    {
        ret = readlink(filename, link, 256);
        link[ret] = '\0'
        return (ft_is_file_or_dir(link));
    }
    return (0);
}
