/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/21 19:49:05 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>

/*
** Flags = -lRartufd
** All flags are represented
** by an integer, where n-th
** bit is n-th flag.
** 1: -l – long format;
** 2: -R – recursive;
** 4: -a – all files;
** 8: -r – reversed;
** 16: -t – sort by mtime;
** 32: -u – sort by atime;
** 64: -f – unsorted (also turns on -a option);
** 128: -d – dirs are listed as plain files.
*/

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;

/*
** A linked list of files.
** All data, except filename
** and filepath, are stored
** in the stat structure.
*/

typedef struct			s_file
{
	char			*name;
	char			*path;
	t_stat			stats;
	struct s_file	*next;
}						t_file;

int						ft_parse_option(char *option, int *flags);
int						ft_parse_options(int argc, char **argv, int *flags);
char					*ft_get_path(char *path, char *name);
void					ft_add_file(char *path, char *name, t_file **file_list);
void					ft_sort_names(char **names);
t_file					*ft_file_list(int argc, char **file_names, int flags);
int						ft_is_first(t_file *files);
t_file					*ft_read_dir(char *path, int flags);
int						ft_nbrlen(int n);
int						ft_max(int a, int b);
int						ft_namecmp(t_file *file_1, t_file *file_2);
int						ft_atimecmp(t_file *file_1, t_file *file_2);
int						ft_mtimecmp(t_file *file_1, t_file *file_2);
t_file					*ft_files_swap(t_file *file_1, t_file *file_2);
t_file					*ft_sort_list(t_file *list,
						int (*cmp)(t_file*, t_file*));
t_file					*ft_reverse_list(t_file *list);
void					ft_sort_files(t_file **files, int flags);
void					ft_print_short(t_file *files);
int						ft_get_width(t_file *files, int tab[7]);
void					ft_print_chmod(t_file *file);
void					ft_print_time(t_file *file, int flags);
void					ft_print_long_one(t_file *file,
						int flags, int width[7]);
void					ft_print_long(t_file *files, int flags);
void					ft_print_files(t_file **files, int flags);
void					ft_print_all(t_file *file_list, int flags);
void					ft_free_files(t_file **files);
void					ft_error(char c, int error);

#endif
