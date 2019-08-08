/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:44:33 by ykopiika          #+#    #+#             */
/*   Updated: 2019/02/20 18:44:40 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		f_bzero(int *b, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		b[i] = 0;
		i++;
	}
}

static void		f_write(t_var v, t_tetra *lst)
{
	while (++v.i <= 3)
	{
		v.j = -1;
		while (++v.j <= 3)
		{
			if (v.s[v.i][v.j] == '#' && v.iy == -1 && v.jx == -1)
			{
				v.iy = v.i;
				v.jx = v.j;
			}
			else if (v.s[v.i][v.j] == '#' && v.iy != -1 && v.jx != -1)
			{
				lst->arr[v.k] = v.j - v.jx;
				lst->arr[v.k + 1] = v.iy - v.i;
				v.k += 2;
			}
		}
	}
}

static t_tetra	*get_lst(t_tetra *lst)
{
	if (!lst)
	{
		if (!(lst = (t_tetra *)malloc(sizeof(t_tetra))))
			f_error(4);
		f_bzero(&lst->arr[0], 6);
		lst->next = NULL;
		lst->prev = NULL;
		lst->character = 65;
		lst->p.x = -1;
		lst->p.y = -1;
		return (lst);
	}
	else
	{
		if (!(lst->next = (t_tetra *)malloc(sizeof(t_tetra))))
			f_error(4);
		f_bzero(&lst->next->arr[0], 6);
		lst->next->next = NULL;
		lst->next->prev = lst;
		lst->next->character = lst->character + 1;
		lst->next->p.x = -1;
		lst->next->p.y = -1;
		return (lst->next);
	}
}

t_tetra			*f_read_tetra(int fd)
{
	t_var		v;
	t_tetra		*lst;

	v.i = -1;
	v.k = 0;
	lst = NULL;
	while ((v.rd = read(fd, &v.buf[0], 21)) > 0)
	{
		lst = get_lst(lst);
		v.buf[v.rd] = '\0';
		v.s = f_strsplit(&v.buf[0], '\n');
		v.k = 0;
		v.i = -1;
		v.iy = -1;
		v.jx = -1;
		f_write(v, lst);
		f_check_tetra(lst->arr);
		f_free(v.s, 4);
	}
	return (lst);
}
