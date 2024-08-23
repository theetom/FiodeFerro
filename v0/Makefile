# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 12:34:36 by toferrei          #+#    #+#              #
#    Updated: 2024/06/28 14:17:32 by toferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf.a

LIBFT	= libft/
MLX		= minilibx-linux/
LIBFT_A	= $(addprefix $(LIBFT), libft.a)
MLX_A	= $(addprefix $(MLX), libmlx_Linux.a)
SOURCES	= \

	
	
OBJECTS = $(SOURCES:.c=.o)

CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -Lminilbx-linux minilibx-linux/libmlx_Linux.a Libft/libft.a -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re