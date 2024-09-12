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

NAME    = fdf

LIBFT   = Libft/
MLX     = minilibx-linux/
LIBFT_A = $(LIBFT)libft.a
MLX_A   = $(MLX)libmlx_Linux.a
SOURCES = sources/fdf.c \
          sources/get_next_line.c \
          sources/mlx_hooks.c \
          sources/mlx_utils.c \
          sources/points_creator.c \
          sources/struct_init.c \
          sources/two_to_three.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I$(MLX) -I$(LIBFT) 
LDFLAGS = -L$(MLX) -lmlx -L$(LIBFT) -lft -lX11 -lXext -lm

# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJECTS)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJECTS)

# Full clean
fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(MLX) clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Code formatting
norminette:
	norminette sources/

# Phony targets
.PHONY: all clean fclean re norminette