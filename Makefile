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
BONUS_SRC_DIR = src_bonus
BONUS_OBJ_DIR = obj_bonus

SRCS = $(SRC_DIR)/fdf_bresenhan_line.c \
					$(SRC_DIR)/fdf_draw_utils.c \
					$(SRC_DIR)/fdf_colors.c \
					$(SRC_DIR)/fdf_image_utils.c \
					$(SRC_DIR)/fdf_isometric.c \
					$(SRC_DIR)/fdf_model_utils.c \
					$(SRC_DIR)/fdf_window_utils.c \
					$(SRC_DIR)/fdf_main.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

BONUS_SRCS = $(BONUS_SRC_DIR)/fdf_bresenhan_line.c \
					$(BONUS_SRC_DIR)/fdf_draw_utils.c \
					$(BONUS_SRC_DIR)/fdf_colors.c \
					$(BONUS_SRC_DIR)/fdf_image_utils.c \
					$(BONUS_SRC_DIR)/fdf_iso_rotate.c \
					$(BONUS_SRC_DIR)/fdf_cavalier.c \
					$(BONUS_SRC_DIR)/fdf_draw_cavalier.c \
					$(BONUS_SRC_DIR)/fdf_model_utils.c \
					$(BONUS_SRC_DIR)/fdf_window_utils.c \
					$(BONUS_SRC_DIR)/fdf_print_utils.c \
					$(BONUS_SRC_DIR)/fdf_main.c
BONUS_OBJS = $(patsubst $(BONUS_SRC_DIR)/%.c,$(BONUS_OBJ_DIR)/%.o,$(BONUS_SRCS))

NAME = fdf
BONUS_NAME = fdf_bonus

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft -L $(MINILIBX_DIR) -lmlx_Linux -lX11 -lXext -lm -lpthread -ldl

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(MINILIBX_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/libft.a:
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX_DIR)/libmlx_Linux.a:
	@echo "Compiling minilibx..."
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft -L $(MINILIBX_DIR) -lmlx_Linux -lX11 -lXext -lm -lpthread -ldl

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

.PHONY: all clean fclean re
