/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:09:17 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 21:03:58 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_options_error(char option)
{
    ft_putstr("ft_ls: illegal option -- ");
    ft_putchar(option)
    ft_putchar('\n');
    ft_putstr("usage: ft_ls [-lRart] [file ...]\n");
    exit(EXIT_FAILURE);
}

void    ft_opendir_error(char *dir)
{
    ft_putstr("ft_ls: ");
    ft_putstr(dir);
    ft_putstr(": Permission denied\n");
    exit(EXIT_FAILURE);
}
