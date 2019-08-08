/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putendl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:54:56 by ykopiika          #+#    #+#             */
/*   Updated: 2019/03/26 15:55:29 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	f_putchar(char c)
{
	write(1, &c, 1);
}

static void	f_putstr(char const *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			f_putchar(s[i]);
			i++;
		}
	}
}

void		f_putendl(char const *s)
{
	if (s)
		f_putstr(s);
	f_putchar('\n');
}
