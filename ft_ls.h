/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/22 17:25:50 by sghezn           ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>

/*
** Flags = -lRartufd1
** All flags are represented
** by an integer, where n-th
** bit is n-th flag.
** 1: -l – long format;
** 2: -R – recursive;
** 4: -a – all files;
** 8: -r – reversed;
** 16: -t – sort by mtime.
** Bonus flags:
** 32: -u – sort by atime;
** 64: -f – unsorted (also turns on -a option);
** 128: -d – dirs are listed as plain files;
** 256: -1 – output is one entry per line.
*/

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct ttysize	t_tysize;

/*
** An auxillary structure used for columns in short format.
** stores row and column indices for a file.
*/

typedef struct			s_point
{
	int	row;
	int	col;
}						t_point;

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
void					ft_print_one_per_line(t_file **files);
void					ft_print_spaces(int n);
int						ft_max_name_len(t_file **files);
void					ft_print_columns(t_file *files,
						t_point index, int max_len);
void					ft_print_short(t_file *files, int flags);
int						ft_get_width(t_file *files, int tab[7]);
char					ft_filetype(t_file *file);
void					ft_print_chmod(t_file *file);
void					ft_print_time(t_file *file, int flags);
void					ft_print_long_one(t_file *file,
						int flags, int width[7]);
void					ft_print_long(t_file *files, int flags);
void					ft_print_files(t_file **files, int flags);
void					ft_print_all(t_file *file_list, int flags, int first);
void					ft_free_files(t_file **files);
void					ft_error(char c, int error);

#endif
