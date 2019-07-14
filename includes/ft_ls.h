/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 15:01:03 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <grp.h>
# include <pwd.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/dirent.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>

typedef struct	s_flags
{
	int	long_format;
	int	recursive;
	int	all_files;
	int	reversed;
	int	time_m;
	int	time_a;
	int	unsorted;
	int	groupname;
	int	dirs_as_files;
	int	colors;
}				t_flags;

typedef struct	s_options
{
	t_flags	*flags;
	t_list	*dirs;
	t_list	*files;
}				t_options;

typedef struct	s_file
{
	char	*name;
	char	*path;
	char	*username;
	char	*groupname;
	t_stat	stat;
	t_file	*next;
}				t_file;

typedef struct	s_dir
{
	char	*name;
	char	*path;
	t_stat	stat;
	t_file	*files;
	t_dir	*next;
}				t_dir;

int 		ft_is_file_or_dir(char *filename);
void    	ft_add_filename(char *filename, t_options *options);
void    	ft_add_dirname(char *filename, t_options *options);
void    	ft_options_error(char option);
void    	ft_add_option(char c, t_flags *flags);
void    	ft_add_options(char *flags, t_options *options);
t_options	*ft_parse_options(int argc, char **argv);
int     	ft_time_a_diff(char *file_1, char *file_2);
int     	ft_time_m_diff(char *file_1, char *file_2);
void    	ft_sort_list(t_list *list, int (*cmp)(char*, char*));
void    	ft_sort(t_options *options);
char    	*ft_username(uid_t uid);
char    	*ft_groupname(gid_t gid);
void    	ft_add_file(t_file *files, char *name, char *path);
void    	ft_print_files(t_list *files, t_flags *flags);
void		ft_print_all(t_options *options);
void    	ft_free_list(t_list *list);

#endif
