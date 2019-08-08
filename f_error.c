/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:57:23 by ykopiika          #+#    #+#             */
/*   Updated: 2019/02/20 13:57:36 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	f_error(int num_e)
{
	if (num_e == 1)
	{
		f_putendl(ERROR_USAGE);
		exit(1);
	}
	else if (num_e == 2)
	{
		f_putendl(ERROR);
		exit(2);
	}
	else if (num_e == 3)
	{
		f_putendl(ERROR);
		exit(3);
	}
	else if (num_e == 4)
	{
		f_putendl(ERROR);
		exit(4);
	}
	else
		exit(10);
}
