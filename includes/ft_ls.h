/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 09:04:07 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>
# include <sys/dirent.h>

typedef struct	s_options
{
	int		*flags;
	char	**dirs;
	char	**files;
}				t_options;

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

int			ft_get_index(char *str, char c);
void    	ft_add_options(char *flags, t_options *options);
t_options	*ft_parse_options(int argc, char **argv);

#endif
