/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/12 08:52:32 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>
# include <sys/dirent.h>

typedef struct	s_flags
{
	int		long_format;
	int		recursive;
	int		all_files;
	int		reversed_sort;
	int		time_m_sort;
	int		time_a_sort;
	int		unsorted;
	int		group_name;
	int		dir_plain;
	int		colors;
	char	**dirs;
	char	**files;
}				t_flags;

typedef struct	s_file
{
	char	*name;
	char	*path;
	char	*username;
	char	*groupname;
	t_stat	stats;
	t_file	*next;
}				t_file;

typedef struct	s_dir
{
	char	*name;
	t_stat	stats;
	t_file	*files;
	t_dir	*next;
}				t_dir;

int			ft_is_file(char *filename);
int			ft_is_dir(char *filename);
t_flags		ft_parse_flags(int argc, char **argv);

#endif
