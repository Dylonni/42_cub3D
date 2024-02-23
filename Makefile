# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dylan <dylan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 16:42:03 by dylan             #+#    #+#              #
#    Updated: 2024/02/13 18:32:06 by dylan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN		=	src/main.c \
					src/init_elements/init_data.c \
					src/init_elements/init_textures.c \
					src/init_elements/init_player_dir.c \
					src/init_elements/init_raycast.c \
					src/parsing/check_args.c \
					src/parsing/parse_data.c \
					src/parsing/read_data.c \
					src/parsing/fill_color_textures.c \
					src/parsing/create_map.c \
					src/parsing/check_map.c \
					src/parsing/check_map1.c \
					src/parsing/utils.c \
					src/draw/render.c \
					src/draw/texture.c \
					src/draw/utils.c \
					src/parsing/check_textures.c \
					src/free/free.c \
					src/free/game_over.c \
					src/debug/debug.c \
					src/mouv/input_handler.c \
					src/mouv/player_move.c \
					src/mouv/check_move.c \
					src/draw/raycast.c \


SRCS			= ${SRC_MAIN}
OBJ_DIR			= objs
OBJS 			= $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

LIBFT_DIR 		= libft/
MLX_DIR			= mlx_linux/

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= cub3D

all: $(OBJ_DIR) $(OBJS) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@printf "⌛ [\e[1;96mCompiling\033[0m]\033[35m $<\033[0m \n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C ${LIBFT_DIR}
	@make -s -C ${MLX_DIR}
	@$(CC) $(OBJS) $(CFLAGS) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@printf "\033[32;1m\n                   ✅ Project has compiled successfully!          \033[0m"
	@printf "\n\n    [🏳️ FLAGS: \033[0;35m$(CFLAGS)\033[0m]"
	@echo "\033[32;1m\n 💾 Executable \e[7m./$(NAME)\e[27m has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

%.o: %.c
	$(CC) -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean:
	@echo "\033[1;93m\n                        [Cleaning directories with \033[0;96mfclean\033[1;93m]\n\033[0m"
	@make clean
	$(RM) $(NAME)
	$(RM) libft/*.o
	$(RM) libft/libft.a

re:
	@make fclean
	@echo "\033[1;93m\n                             [Calling \033[0;96mmake all\033[1;93m rule]\n\033[0m"
	@make -s all

.PHONY: all clean fclean re
