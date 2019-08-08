/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:42:02 by ykopiika          #+#    #+#             */
/*   Updated: 2019/03/17 18:42:04 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	flood_fill(char **map, int s, t_point p, char c)
{
	t_point t;

	if (p.x >= 0 && p.x < s && p.y >= 0 && p.y < s)
	{
		if (map[p.y][p.x] == c)
		{
			map[p.y][p.x] = '.';
			t.x = p.x + 1;
			t.y = p.y;
			flood_fill(map, s, t, c);
			t.x = p.x - 1;
			flood_fill(map, s, t, c);
			t.x = p.x;
			t.y = p.y + 1;
			flood_fill(map, s, t, c);
			t.y = p.y - 1;
			flood_fill(map, s, t, c);
		}
	}
}
