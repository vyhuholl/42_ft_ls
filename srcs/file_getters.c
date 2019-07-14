/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:11:49 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 13:29:19 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_is_file_or_dir(char *filename)
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
