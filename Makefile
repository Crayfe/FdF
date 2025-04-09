# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 16:58:10 by cayuso-f          #+#    #+#              #
#    Updated: 2025/02/26 16:57:50 by cayuso-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
MINILIBX_DIR = minilibx
SRC_DIR = src
OBJ_DIR = obj

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Nombre del ejecutable
NAME = fdf

# Regla por defecto (compilar el ejecutable)
all:	$(NAME)

# Regla para crear el ejecutable $(NAME)
$(NAME):	$(OBJS) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft -L $(MINILIBX_DIR) -lmlx_Linux -lX11 -lXext -lm -lpthread -ldl

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(MINILIBX_DIR) -c $< -o $@

# Crear el directorio de objetos si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regla para compilar la librería libft.a
$(LIBFT_DIR)/libft.a:
	@echo "Compilando libft..."
	$(MAKE) -C $(LIBFT_DIR)

# Regla para compilar la librería minilibx.a
$(MINILIBX_DIR)/libmlx_Linux.a:
	@echo "Compilando minilibx..."
	$(MAKE) -C $(MINILIBX_DIR)

# Limpiar los archivos generados
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

re: fclean all

.PHONY: all clean fclean re
