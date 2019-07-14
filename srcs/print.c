/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:15:45 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 17:55:24 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_print_files(t_list *files_list, t_flags *flags)
{
    t_file  *files;
    char    *path;

    path = ft_strdup("");
    files = NULL;
    while (files_list)
    {
        if (flags->all_files || files_list->data[0] != '.')
            ft_add_file(files, files_list->data, path);
        files_list = files_list->next;
    }
    ft_sort_filelist(files, flags);
}

void    ft_print_dir(char *path, t_flags *flags)
{
    struct dirent   *entry;
    DIR             *dir;
    t_file          *files;
    t_dir           *dirs;
    char            *new_path;

    files = NULL;
    if (!(dir = opendir(path)))
        ft_opendir_error(path);
    dirs = (t_dir*)malloc(sizeof(t_dir) + 1);
    dirs->name = path;
    new_path = ft_strjoin(path, "/");
    while ((entry = readdir(dir)))
        if (flags-all_files || entry->d_name[0] != '.')
            ft_add_file(files, entry->d_name, new_path);
    ft_sort_filelist(files, flags);
    dirs->files = files;
    closedir(dir);
}

void    ft_recur(char *path, t_dir *dir, t_flags *flags)
{
    t_file  *files;
    char    *temp;

    files = dir->files;
    while (files)
    {
        if (ft_is_file_or_dir(files->name) == 2)
        {
            temp = ft_strjoin(path, files->name);
            ft_print_dir(temp, flags);
            free(temp);
        }
        files = files->next;
    }
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
