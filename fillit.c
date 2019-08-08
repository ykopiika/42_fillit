/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:10:31 by ykopiika          #+#    #+#             */
/*   Updated: 2019/03/24 17:11:00 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	*f_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	unsigned char	c1;
	size_t			i;

	i = 0;
	c1 = (unsigned char)c;
	a = (unsigned char*)b;
	while (i < len)
	{
		a[i] = c1;
		i++;
	}
	if (b == NULL)
		return (NULL);
	return (b);
}

static void	print_map(char **map, int s)
{
	int i;

	i = 0;
	if (map)
	{
		while (i < s)
		{
			f_putendl(map[i]);
			i++;
		}
	}
}

static int	f_square(int s)
{
	int i;

	i = 1;
	while ((i * i) < s)
		i++;
	return (i);
}

static char	**malloc_map(int s)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * s);
	if (!map)
		f_error(4);
	while (i < s)
	{
		map[i] = (char *)malloc(sizeof(char) * s + 1);
		if (!map[i])
			f_error(4);
		f_memset(map[i], '.', s);
		map[i][s] = '\0';
		i++;
	}
	return (map);
}

void		fillit(t_tetra *lst, int s)
{
	int		c_tet;
	char	**map;

	c_tet = 1;
	if (s == 0)
	{
		while (lst->prev != NULL)
		{
			c_tet++;
			lst = lst->prev;
		}
		if (c_tet > 26)
			f_error(3);
		s = c_tet * 4;
		s = f_square(s);
	}
	map = malloc_map(s);
	while (f_write_map(map, s, lst) == 0)
	{
		f_free(map, s);
		s++;
		map = malloc_map(s);
	}
	print_map(map, s);
	f_free(map, s);
}
