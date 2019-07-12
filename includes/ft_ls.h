/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/12 05:38:31 by sghezn           ###   ########.fr       */
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
# include <string.h>

typedef struct	s_file
{
	mode_t	mode;
	nlink_t	n_links;
	uid_t	user_id;
	gid_t	group_id;
	off_t	size;
	time_t	atime;
	time_t	mtime;
	char	*name;
	t_file	*next;
}				t_file;

int		ft_index(char c, char *str);
int		ft_raise_error(char *str, int error);
int		*ft_parse_options(int argc, char **argv);
t_file  *ft_create_new_file(char *name, t_stat *stat);
int     ft_add_new_file(char *name, t_file **list);
t_file	*ft_create_file_list(int argc, char **argv);
void    ft_free_list(t_file *list);

#endif
