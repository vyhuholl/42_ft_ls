/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:21:10 by sghezn            #+#    #+#             */
/*   Updated: 2019/06/07 04:44:45 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_print_bits(mode_t mode)
{
    ft_putchar((mode & S_IRUSR) ? 'r' : '-');
    ft_putchar((mode & S_IWUSR) ? 'w' : '-');
    ft_putchar((mode & S_IXUSR) ? 'x' : '-');
    ft_putchar((mode & S_IRGRP) ? 'r' : '-');
    ft_putchar((mode & S_IWGRP) ? 'w' : '-');
    ft_putchar((mode & S_IXGRP) ? 'x' : '-');
    ft_putchar((mode & S_IROTH) ? 'r' : '-');
    ft_putchar((mode & S_IWOTH) ? 'w' : '-');
    ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}

void    ft_print_mode(mode_t mode)
{
    if ((mode & S_IFMT) == S_IFREG)
        ft_putchar('-');
    if ((mode & S_IFMT) == S_IFDIR)
        ft_putchar('d');
    if ((mode & S_IFMT) == S_IFBLK)
        ft_putchar('b');
    if ((mode & S_IFMT) == S_IFSOCK)
        ft_putchar('s');
    if ((mode & S_IFMT) == S_IFCHR)
        ft_putchar('c');
    if ((mode & S_IFMT) == S_IFLNK)
        ft_putchar('l');
    if ((mode & S_IFMT) == S_IFIFO)
        ft_putchar('f');
    ft_print_bits(mode);
}

// void	print_total(void)
// {
// 	;
// }

// ft_printf("%d\n", buf.st_dev);
// ft_printf("%d\n", buf.st_ino);
// ft_printf("%d\n", buf.st_mode);
// ft_printf("%d\n", buf.st_nlink);
// ft_printf("%d\n", buf.st_uid);
// ft_printf("%d\n", buf.st_gid);
// ft_printf("%d\n", buf.st_rdev);
// ft_printf("%d\n", buf.st_size);
// ft_printf("%d\n", buf.st_blocks);
// ft_printf("%d\n", buf.st_blksize);
// ft_printf("%d\n", buf.st_flags);
// ft_printf("%d\n", buf.st_gen);
// ft_printf("%d\n", buf.st_atimespec.tv_nsec);
// ft_printf("%d\n", buf.st_atimespec.tv_sec);
// ft_printf("%d\n", buf.st_mtimespec.tv_nsec);
// ft_printf("%d\n", buf.st_mtimespec.tv_sec);
// ft_printf("%d\n", buf.st_ctimespec.tv_nsec);
// ft_printf("%d\n", buf.st_ctimespec.tv_sec);

void	print_l_flag(char *filepath, struct stat buf)
{
	char	*tmp;

	ft_print_mode(buf.st_mode);
	ft_printf("  %d ", buf.st_nlink);
	ft_printf("%s  ", getpwuid(buf.st_uid)->pw_name);
	ft_printf("%s  ", getgrgid(buf.st_gid)->gr_name);
	ft_printf("%d ", buf.st_size);
	tmp = ctime(&(buf.st_mtimespec.tv_sec));
	ft_printf("%s", ft_strsub(tmp, 4, ft_strlen(tmp) - 13));
	ft_printf(" %s\n", filepath);
}
