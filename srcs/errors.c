/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:09:17 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 09:09:00 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_options_error(char option)
{
    ft_putstr_fd("ft_ls: illegal option -- ", 2);
    ft_putchar_fd(option, 2)
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("usage: ft_ls [-lRartufgdG] [file ...]\n", 2);
    exit(EXIT_FAILURE);
}
