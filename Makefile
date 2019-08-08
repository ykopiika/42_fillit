# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 14:51:42 by ykopiika          #+#    #+#              #
#    Updated: 2019/02/21 14:51:45 by ykopiika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SOURCE = f_check_file.c f_check_tetra.c f_error.c f_read_tetra.c f_write_map.c fillit.c flood_fill.c main.c f_free.c f_strsub.c f_putendl.c f_strsplit.c\

HEADER = fillit.h

OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
