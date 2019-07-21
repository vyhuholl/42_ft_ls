/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:47:19 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/21 13:15:32 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** 3 auxillary functions used for comparison.
*/

int ft_namecmp(t_file *file_1, t_file *file_2)
{
    return (ft_strcmp(file_1->name, file_2->name));
}

int ft_atimecmp(t_file *file_1, t_file *file_2)
{
    return ((int)(file_1->stats.st_atimespec.tv_sec -
    file_2->stats.st_atimespec.tv_sec));
}

int ft_mtimecmp(t_file *file_1, t_file *file_2)
{
    return ((int)(file_1->stats.st_mtimespec.tv_sec -
    file_2->stats.st_mtimespec.tv_sec));
}

/*
** An auxillary function used to find maximum of two integers.
*/

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

/*
** An auxillary function used to compute
** the length of a non-negative integer number.
*/

int ft_nbrlen(int n)
{
    int len;

    len = 1;
    while (n >= 10)
    {
        n /= 10;
        len++;
    }
    return (len);
}
