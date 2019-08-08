/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:33:39 by ykopiika          #+#    #+#             */
/*   Updated: 2019/02/19 17:33:42 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define ERROR_USAGE "usage: ./fillit source_file.fillit"
# define ERROR "error"
# define R(x, y) if(x) return (y);

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_tetra
{
	int					arr[6];
	char				character;
	t_point				p;
	struct s_tetra		*next;
	struct s_tetra		*prev;
}						t_tetra;

typedef struct			s_var
{
	char				**s;
	char				buf[22];
	int					rd;
	int					i;
	int					j;
	int					k;
	int					iy;
	int					jx;
}						t_var;

t_tetra					*f_read_tetra(int fd);
void					f_error(int num_e);
void					f_check_file(int fd);
void					f_check_tetra(int *a);
void					fillit(t_tetra *lst, int s);
void					flood_fill(char **map, int s, t_point p, char c);
void					f_free(char **map, int s);
void					f_putendl(char const *s);
char					*f_strsub(char const *s, unsigned int start, size_t l);
char					**f_strsplit(char const *s, char c);
int						f_write_map(char **map, int s, t_tetra *lst);

#endif
