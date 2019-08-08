/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:36:38 by ykopiika          #+#    #+#             */
/*   Updated: 2019/03/06 16:36:41 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check1(int *a)
{
	R(a[2] == -1 && a[3] == -1 && a[4] == 0 && a[5] == -1, 1);
	R(a[2] == 1 && a[3] == -1 && a[4] == 2 && a[5] == -1, 1);
	R(a[2] == 0 && a[3] == -1 && a[4] == 0 && a[5] == -2, 1);
	R(a[2] == 0 && a[3] == -1 && a[4] == 1 && a[5] == -1, 1);
	R(a[2] == 1 && a[3] == -1 && a[4] == 1 && a[5] == -2, 1);
	R(a[2] == 2 && a[3] == 0 && a[4] == 3 && a[5] == 0, 1);
	R(a[2] == 2 && a[3] == 0 && a[4] == 0 && a[5] == -1, 1);
	R(a[2] == 2 && a[3] == 0 && a[4] == 1 && a[5] == -1, 1);
	R(a[2] == 2 && a[3] == 0 && a[4] == 2 && a[5] == -1, 1);
	return (0);
}

static int	check2(int *a)
{
	R(a[0] == 0 && a[2] == 0 && a[3] == -2 && a[4] == 0 && a[5] == -3, 1);
	R(a[0] == 0 && a[2] == -1 && a[3] == -2 && a[4] == 0 && a[5] == -2, 1);
	R(a[0] == 0 && a[2] == 0 && a[3] == -2 && a[4] == 1 && a[5] == -2, 1);
	R(a[0] == 0 && a[2] == 1 && a[3] == -1 && a[4] == 2 && a[5] == -1, 1);
	R(a[0] == 0 && a[2] == 1 && a[3] == -1 && a[4] == 1 && a[5] == -2, 1);
	R(a[0] == 0 && a[2] == 1 && a[3] == -1 && a[4] == 0 && a[5] == -2, 1);
	R(a[0] == -2 && a[2] == -1 && a[3] == -1 && a[4] == 0 && a[5] == -1, 1);
	R(a[0] == -1 && a[2] == 0 && a[3] == -1 && a[4] == 1 && a[5] == -1, 1);
	R(a[0] == -1 && a[2] == 0 && a[3] == -1 && a[4] == 0 && a[5] == -2, 1);
	R(a[0] == -1 && a[2] == 0 && a[3] == -1 && a[4] == -1 && a[5] == -2, 1);
	return (0);
}

void		f_check_tetra(int *a)
{
	if (a[0] == 1 && a[1] == 0)
	{
		if (check1(a) == 1)
			return ;
	}
	else if (a[1] == -1)
	{
		if (check2(a) == 1)
			return ;
	}
	f_error(3);
}