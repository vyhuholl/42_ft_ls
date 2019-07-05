/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/06/07 04:28:42 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

# define ALL_FLAGS "lRart"
# define NUM_FLAGS 5

typedef struct			s_paths
{
	struct stat			buf;
	char				*filepath;
	struct s_paths		*next;
}						t_paths;

/*
**	flags
**	[0]: l
**	[1]: R
**	[2]: a
**	[3]: r
**	[4]: t
*/

typedef struct			s_input
{
	int					flags[NUM_FLAGS];
	t_paths				*paths;
}						t_input;

/*
**	Type - 0 for files, 1 for dirs, 2 for symbolic links.
*/

typedef struct			s_file
{
	char				*name;
	char				*full_path;
	int					type;
	int					mode;
	int					size;
	time_t				time;
}						t_file;

enum {
	e_illegal_option,
	e_malloc_error,
};

t_list			*ft_read_dir(char *filepath, struct stat buf);
void			add_path(t_input *input, char *path);
void			error_exit(int value, char *path);
void			reverse_paths_and_bufs(t_input *input);
t_input			*parse_input(int argc, char **argv);
void			print_l_flag(char *filepath, struct stat buf);

t_list	*ft_read_dir(t_flags *flags, char *pathname);
void    ft_print_bits(mode_t mode);
void    ft_print_mode(mode_t mode);
void    ft_print_time(time_t mtime);
void    ft_print_long(t_file *file);
#endif
