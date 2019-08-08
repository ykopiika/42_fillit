/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_write_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:24:12 by ykopiika          #+#    #+#             */
/*   Updated: 2019/03/19 15:24:23 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_size(char **map, int s, t_tetra *lst, t_point v)
{
	int k;

	k = 0;
	if (map[v.x][v.y] == '.')
	{
		while (k < 6)
		{
			if (!(v.x - lst->arr[k + 1] >= 0 && v.x - lst->arr[k + 1] < s))
				break ;
			else if (!(v.y + lst->arr[k] >= 0 && v.y + lst->arr[k] < s))
				break ;
			else if (map[v.x - lst->arr[k + 1]][v.y + lst->arr[k]] != '.')
				break ;
			k += 2;
		}
		if (k == 6)
		{
			lst->p.y = v.x;
			lst->p.x = v.y;
			return (1);
		}
	}
	return (0);
}

static int		srch_free_pleace(char **map, int s, t_tetra *lst)
{
	t_point v;

	if (lst->p.y == -1)
	{
		v.x = -1;
		v.y = -1;
	}
	else
	{
		v.x = lst->p.y - 1;
		v.y = lst->p.x - 1;
	}
	while (++v.x < s)
	{
		if (v.x == lst->p.y)
			v.y = lst->p.x - 1;
		else
			v.y = -1;
		while (++v.y < s)
			if (check_size(map, s, lst, v) == 1)
				return (1);
	}
	return (0);
}

static char		**write_tetra_in_map(char **map, t_tetra *lst)
{
	int			i;
	t_point		p;

	i = 0;
	p = lst->p;
	map[p.y][p.x] = lst->character;
	while (i < 6)
	{
		map[p.y - lst->arr[i + 1]][p.x + lst->arr[i]] = lst->character;
		i += 2;
	}
	return (map);
}

static t_tetra	*del_tetra(char **map, int s, t_tetra *lst)
{
	lst->p.x = -1;
	lst->p.y = -1;
	lst = lst->prev;
	flood_fill(map, s, lst->p, lst->character);
	if (lst->p.x + 1 < s && lst->p.y < s)
		lst->p.x += 1;
	else if (((lst->p.y + 1) >= 0) && ((lst->p.y + 1) < s))
	{
		lst->p.x = 0;
		lst->p.y += 1;
	}
	return (lst);
}

int				f_write_map(char **map, int s, t_tetra *lst)
{
	int res;

	while (lst)
	{
		res = srch_free_pleace(map, s, lst);
		if (res == 1)
		{
			map = write_tetra_in_map(map, lst);
			lst = lst->next;
		}
		else if (res == 0 && lst->prev)
			lst = del_tetra(map, s, lst);
		else if (res == 0 && !lst->prev)
		{
			lst->p.x = -1;
			lst->p.y = -1;
			break ;
		}
	}
	if (lst && res == 0 && !lst->prev)
		return (0);
	else
		return (1);
}
