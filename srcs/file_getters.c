/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:11:49 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/15 03:44:52 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    *ft_username(uid_t uid)
{
    struct passwd   *pwd;

    if (!(pwd = getpwuid(uid)))
        return (ft_itoa(uid));
    return (ft_strdup(pwd->pw_name));
}

char    *ft_groupname(gid_t gid)
{
    struct group   *grp;

    if (!(grp = getgrgid(gid)))
        return (ft_itoa(gid));
    return (ft_strdup(grp->gr_name));
}

void    ft_add_file(t_file *files, char *name, char *path)
{
    t_file      *ptr;
    t_file      *file;
    struct stat stats;

    file = (t_file*)malloc(sizeof(t_file) + 1);
    file->name = ft_strdup(name);
    file->path = ft_strjoin(path, name);
    lstat(name, &stats);
    file->stats = stats;
    file->username = ft_username(stats.st_uid);
    file->groupname = ft_groupname(stats.st_gid);
    file->next = NULL;
    if (!files)
        files = file;
    else 
    {
        ptr = files;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = file;
    }
}

char    ft_filetype(t_file *file)
{
    if (S_ISBLK(file->stats.st_mode))
        return ('b');
    else if (S_ISCHR(file->stats.st_mode))
        return ('c');
    else if (S_ISDIR(file->stats.st_mode))
        return ('d');
    else if (S_ISFIFO(file->stats.st_mode))
        return ('p');
    else if (S_ISLNK(file->stats.st_mode))
        return ('l');
    else if (S_ISSOCK(file->stats.st_mode))
        return ('s');
    return ('-');
}

int     ft_is_file_or_dir(char *filename)
{
    struct stat stats;
    char        link[256];
    ssize_t     ret;

    lstat(filename, &stats);
    if (S_ISREG(stats.st_mode))
        return (1);
    else if (S_ISDIR(stats.st_mode))
        return (2);
    else if (S_ISLNK(stats.st_mode))
    {
        ret = readlink(filename, link, 256);
        link[ret] = '\0';
        return (ft_is_file_or_dir(link));
    }
    return (0);
}
