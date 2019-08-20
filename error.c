/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:02:02 by sghezn            #+#    #+#             */
/*   Updated: 2019/08/20 20:24:40 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_memory_error(int flags)
{
	int	fd;

	fd = (flags & 512) ? STD_OUT : STD_ERR;
	ft_putstr_fd(strerror(ENOMEM), fd);
	exit(EXIT_FAILURE);
}

void	ft_options_error(char op, int flags)
{
	int	fd;

	fd = (flags & 512) ? STD_OUT : STD_ERR;
	ft_putstr_fd("ls: illegal option -- ", fd);
	ft_putchar_fd(op, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUW", fd);
	ft_putstr_fd("abcdefghiklmnopqrstuwx1] [file ...]", fd);
	exit(EXIT_FAILURE);
}

void	ft_not_found_error(t_list *files, int flags)
{
	int	fd;

	fd = (flags & 512) ? STD_OUT : STD_ERR;
	ft_lstreverse(&files);
	while (files)
	{
		ft_putstr_fd("ls: ", fd);
		ft_putstr_fd(files->content, fd);
		ft_putstr_fd(": No such file or directory\n", fd);
		files = files->next;
	}
	exit(EXIT_FAILURE);
}

void	ft_fts_error(int flags)
{
	int	fd;

	fd = (flags & 512) ? STD_OUT : STD_ERR;
	ft_putstr_fd("ls: fts_open: No such file or directory", fd);
	exit(EXIT_FAILURE);
}

void	ft_permission_error(char *path, int flags)
{
	int	fd;

	fd = (flags & 512) ? STD_OUT : STD_ERR;
	ft_putstr_fd("ls: ", fd);
	ft_putstr_fd(path, fd);
	ft_putstr_fd(": Permission denied\n", fd);
	exit(EXIT_FAILURE);
}
