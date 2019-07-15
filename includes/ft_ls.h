/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/15 04:27:04 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>

typedef struct	s_flags
{
	int	long_format;
	int	recursive;
	int	all_files;
	int	reversed;
	int	time_m;
}				t_flags;

typedef struct	s_options
{
	char	*path;
	t_flags	*flags;
	t_list	*dirs;
	t_list	*files;
}				t_options;

typedef struct	s_file
{
	char			*name;
	char			*path;
	char			*username;
	char			*groupname;
	struct stat		stats;
	struct s_file	*next;
}				t_file;

typedef struct	s_dir
{
	char			*name;
	t_file			*files;
	struct s_dir	*next;
}				t_dir;

typedef struct	s_len
{
	int	total;
	int	nlink_len;
	int	user_len;
	int	group_len;
	int	size_len;
	int	major_len;
	int	minor_len;
	int	name_len;
}				t_len;

int 		ft_max(int x, int y);
int 		ft_nbrlen(int n);
char    	ft_filetype(t_file *file);
int 		ft_is_file_or_dir(char *filename);
void    	ft_add_filename(char *filename, t_options *options);
void    	ft_add_dirname(char *filename, t_options *options);
void    	ft_opendir_error(char *dir);
void    	ft_options_error(char option);
void    	ft_add_option(char c, t_flags *flags);
void    	ft_add_options(char *flags, t_options *options);
t_options	*ft_parse_options(int argc, char **argv);
int     	ft_time_m_diff(const char *file_1, const char *file_2);
void    	ft_sort_list(t_list *list, int (*cmp)(const char*, const char*));
void    	ft_sort(t_options *options);
char    	*ft_username(uid_t uid);
char    	*ft_groupname(gid_t gid);
void    	ft_add_file(t_file *files, char *name, char *path);
void    	ft_swap_files(t_file *file_1, t_file *file_2);
void    	ft_sort_files(t_file *files, int (*cmp)(const char*, const char*));
void    	ft_reverse_files(t_file *files);
void    	ft_sort_filelist(t_file *files_list, t_flags *flags);
void    	ft_print_files(t_list *files, t_flags *flags);
void    	ft_print_dir(char *path, t_flags *flags);
void    	ft_recur(char *path, t_dir *dir, t_flags *flags);
void		ft_print_all(t_options *options);
void        ft_compute_single_len(t_file *file, t_len *len);
t_format    *ft_compute_len(t_file *files);
void        ft_show_file(t_file *file, t_flags *flags, t_len *len);
void    	ft_show_files(t_file *files, t_flags *flags);
void    	ft_show_dir(t_dir *dir, t_flags *flags);
void    	ft_print_time(time_t *time);
void    	ft_printmod(t_file *file);
void    	ft_print_long(t_file *file, t_flags *flags, t_len *len);
void    	ft_free_list(t_list *list);
void    	ft_free_file(t_file *file);
void    	ft_free_dir(t_dir *dir);

#endif
