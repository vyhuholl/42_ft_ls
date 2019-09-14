/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:02:02 by sghezn            #+#    #+#             */
/*   Updated: 2019/09/14 16:33:39 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_memory_error(void)
{
	ft_putstr_fd(strerror(ENOMEM), 2);
	if (STDOUT_FILENO != STDERR_FILENO)
		exit(EXIT_FAILURE);
}

void	ft_options_error(char op)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(op, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUW", 2);
	ft_putstr_fd("abcdefghiklmnopqrstuwx1] [file ...]\n", 2);
	if (STDOUT_FILENO != STDERR_FILENO)
		exit(EXIT_FAILURE);
}

void	ft_not_found_error(t_list *files)
{
	while (files)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(files->content, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		files = files->next;
	}
}

void	ft_fts_error(void)
{
	ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
	if (STDOUT_FILENO != STDERR_FILENO)
		exit(EXIT_FAILURE);
}

void	ft_permission_error(char *name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	if (STDOUT_FILENO != STDERR_FILENO)
		exit(EXIT_FAILURE);
}
