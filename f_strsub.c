/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:38:32 by ykopiika          #+#    #+#             */
/*   Updated: 2019/03/26 16:38:34 by ykopiika         ###   ########.fr       */
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

static void	*f_memalloc(size_t size)
{
	void	*p;

	p = malloc(sizeof(void) * size);
	if (p == 0)
		return (NULL);
	f_memset(p, 0, size);
	return (p);
}

static char	*f_strnew(size_t size)
{
	char	*s;

	s = f_memalloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	return (s);
}

char		*f_strsub(char const *s, unsigned int start, size_t l)
{
	char	*sub;
	size_t	i;

	if (!s || !*s)
		return (NULL);
	sub = f_strnew(l);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < l && s[(size_t)start + i] != '\0')
	{
		sub[i] = s[(size_t)start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
