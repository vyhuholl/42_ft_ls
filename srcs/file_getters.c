/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:11:49 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 09:32:34 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_is_file(char *filename)
{
    t_stat  stat;
    char    link[256];
    ssize_t ret;

    lstat(filename, stat);
    if (S_ISREG(stat.st_mode) || ! stat.st_mode)
        return (1);
    else if (S_ISLNK(stat.st_mode))
    {
        ret = readlink(filename, link, 256);
        link[ret] = '\0'
        if (ft_is_file(link))
            return (1);
    }
    return (0);
}
