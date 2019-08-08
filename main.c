/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:33:56 by ykopiika          #+#    #+#             */
/*   Updated: 2019/02/19 17:34:23 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int		fd;
	t_tetra	*lst;

	if (ac != 2)
		f_error(1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		f_error(2);
	f_check_file(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	lst = f_read_tetra(fd);
	close(fd);
	fillit(lst, 0);
	return (0);
}
