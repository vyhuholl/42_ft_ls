/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:02:02 by sghezn            #+#    #+#             */
/*   Updated: 2019/09/03 17:58:51 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_memory_error(void)
{
	t_stat	std_out;
	t_stat	std_err;

	ft_putstr_fd(strerror(ENOMEM), 2);
	if (fstat(STDOUT_FILENO, &std_out) == 0 &&
		fstat(STDERR_FILENO, &std_err) == 0 &&
		S_ISCHR(std_out.st_mode) &&
		S_ISCHR(std_err.st_mode) &&
		(std_out.st_dev != std_err.st_dev ||
		std_out.st_ino != std_err.st_ino))
		exit(EXIT_FAILURE);
}

void	ft_options_error(char op)
{
	t_stat	std_out;
	t_stat	std_err;

	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(op, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUW", 2);
	ft_putstr_fd("abcdefghiklmnopqrstuwx1] [file ...]", 2);
	if (fstat(STDOUT_FILENO, &std_out) == 0 &&
		fstat(STDERR_FILENO, &std_err) == 0 &&
		S_ISCHR(std_out.st_mode) &&
		S_ISCHR(std_err.st_mode) &&
		(std_out.st_dev != std_err.st_dev ||
		std_out.st_ino != std_err.st_ino))
		exit(EXIT_FAILURE);
}

void	ft_not_found_error(t_list *files)
{
	t_stat	std_out;
	t_stat	std_err;

	ft_lstreverse(&files);
	while (files)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(files->content, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		files = files->next;
	}
	if (fstat(STDOUT_FILENO, &std_out) == 0 &&
		fstat(STDERR_FILENO, &std_err) == 0 &&
		S_ISCHR(std_out.st_mode) &&
		S_ISCHR(std_err.st_mode) &&
		(std_out.st_dev != std_err.st_dev ||
		std_out.st_ino != std_err.st_ino))
		exit(EXIT_FAILURE);
}

void	ft_fts_error(void)
{
	t_stat	std_out;
	t_stat	std_err;

	ft_putstr_fd("ls: fts_open: No such file or directory", 2);
	if (fstat(STDOUT_FILENO, &std_out) == 0 &&
		fstat(STDERR_FILENO, &std_err) == 0 &&
		S_ISCHR(std_out.st_mode) &&
		S_ISCHR(std_err.st_mode) &&
		(std_out.st_dev != std_err.st_dev ||
		std_out.st_ino != std_err.st_ino))
		exit(EXIT_FAILURE);
}

void	ft_permission_error(char *name)
{
	t_stat	std_out;
	t_stat	std_err;

	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	if (fstat(STDOUT_FILENO, &std_out) == 0 &&
		fstat(STDERR_FILENO, &std_err) == 0 &&
		S_ISCHR(std_out.st_mode) &&
		S_ISCHR(std_err.st_mode) &&
		(std_out.st_dev != std_err.st_dev ||
		std_out.st_ino != std_err.st_ino))
		exit(EXIT_FAILURE);
}
