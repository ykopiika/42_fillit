/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:14:59 by ykopiika          #+#    #+#             */
/*   Updated: 2019/02/21 15:15:01 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		check_hash(char *s)
{
	int i;

	i = 0;
	while (*s)
		if (*s++ == '#')
			i++;
	if (i != 4)
		f_error(3);
}

static void		chek_last_read(int rd, char *p, int nl_count)
{
	char *ptr;

	ptr = p;
	if (rd == 20)
	{
		p[rd] = '\0';
		check_hash(p);
		nl_count = 0;
		while (*p != '\0')
			if (*p++ == '\n')
				nl_count++;
		p = ptr;
		if (p[4] != '\n' || p[9] != '\n' || p[14] != '\n' ||
			p[19] != '\n' || p[20] != '\0' || nl_count != 4)
			f_error(2);
		while (*p != '\0')
		{
			if (*p != '\n' && *p != '#' && *p != '.')
				f_error(2);
			p++;
		}
	}
	else
		f_error(2);
}

void			f_check_file(int fd)
{
	int		rd;
	int		nl_count;
	char	buf[22];
	char	*p;

	while ((rd = read(fd, &buf[0], 21)) == 21)
	{
		p = &buf[0];
		p[rd] = '\0';
		check_hash(&buf[0]);
		nl_count = 0;
		while (*p != '\0')
			if (*p++ == '\n')
				nl_count++;
		p = &buf[0];
		if (p[4] != '\n' || p[9] != '\n' || p[14] != '\n' ||
			p[19] != '\n' || p[20] != '\n' || nl_count != 5)
			f_error(2);
		while (*p != '\0')
		{
			R(*p != '\n' && *p != '#' && *p != '.', f_error(2));
			p++;
		}
	}
	chek_last_read(rd, &buf[0], nl_count);
}
