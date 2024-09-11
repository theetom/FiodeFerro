# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 12:34:36 by toferrei          #+#    #+#              #
#    Updated: 2024/09/11 18:40:02 by toferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf.a

LIBFT	= Libft/
MLX		= minilibx-linux/
LIBFT_A	= $(addprefix $(LIBFT), libft.a)
MLX_A	= $(addprefix $(MLX), libmlx_Linux.a)
SOURCES	= sources/fdf.c \
		sources/get_next_line.c \
		sources/mlx_hooks.c \
		sources/mlx_utils.c \
		sources/points_creator.c \
		sources/struct_init.c \
		sources/two_to_three.c

	
	
OBJECTS = $(SOURCES:.c=.o)

CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -Lminilibx-linux -lmlx_Linux -LLibft -lft -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C Libft
	@make -C minilibx-linux
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -o $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	@make -C Libft fclean
	@make -C minilibx-linux clean
	rm -f $(NAME)

re: fclean all

norminette:
		norminette sources/

.PHONY: all clean fclean re norminette