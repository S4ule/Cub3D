NAME	  =		cub3D
NAMEBONUS =		cub3Dbonus

SRC_DIR   = 	srcs
SRC_DIRB  = 	srcs_bonus
OBJ_DIR   = 	.objs
OBJ_DIRB   = 	.objsbonus

LIBFT_DIR = 	libft
GNL_DIR	  = 	gnl
MLX_DIR	  =		minilibx-linux

LIBFT 	  = 	$(LIBFT_DIR)/libft.a
GNL 	  = 	$(GNL_DIR)/libget_next_line.a
LMLX	  =		$(MLX_DIR)/libmlx_Linux.a

SRC		  =		$(SRC_DIR)/main.c\
				$(SRC_DIR)/error.c\
				$(SRC_DIR)/images.c\
				$(SRC_DIR)/map.c\
				$(SRC_DIR)/map_screen.c\
				$(SRC_DIR)/utils.c\
				$(SRC_DIR)/mapping.c\
				$(SRC_DIR)/color.c\
				$(SRC_DIR)/color_screen.c\
				$(SRC_DIR)/free.c\
				$(SRC_DIR)/check.c\
				$(SRC_DIR)/map_checker.c\
				$(SRC_DIR)/checkutils.c\
				$(SRC_DIR)/game.c\
				$(SRC_DIR)/keys.c\

SRCBONUS  =		$(SRC_DIRB)/main_bonus.c\
				$(SRC_DIRB)/error_bonus.c\
				$(SRC_DIRB)/images_bonus.c\
				$(SRC_DIRB)/map_bonus.c\
				$(SRC_DIRB)/map_screen_bonus.c\
				$(SRC_DIRB)/utils_bonus.c\
				$(SRC_DIRB)/mapping_bonus.c\
				$(SRC_DIRB)/color_bonus.c\
				$(SRC_DIRB)/color_screen_bonus.c\
				$(SRC_DIRB)/free_bonus.c\
				$(SRC_DIRB)/map_checker_bonus.c\
				$(SRC_DIRB)/check_bonus.c\
				$(SRC_DIRB)/checkutils_bonus.c\
				$(SRC_DIRB)/game_bonus.c\
				$(SRC_DIRB)/keys_bonus.c\
				$(SRC_DIRB)/minimap_bonus.c\
				$(SRC_DIRB)/mouse_bonus.c\
				$(SRC_DIRB)/homer_bonus.c\
				$(SRC_DIRB)/homerbis_bonus.c\
				$(SRC_DIRB)/init_bonus.c\
				$(SRC_DIRB)/door_bonus.c\
				$(SRC_DIRB)/score_bonus.c\
				$(SRC_DIRB)/hulk_bonus.c\
				$(SRC_DIRB)/hulkbis_bonus.c\

OBJ		  =		$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
OBJBONUS  =		$(patsubst $(SRC_DIRB)%.c, $(OBJ_DIRB)%.o, $(SRCBONUS))

CC		  =		gcc
FLAGS	  =		-Wall -Wextra -Werror -g
HEAD 	  =     -I./include -I./$(LIBFT_DIR) -I./$(GNL_DIR)
LFLAGS    =     -L ./$(LIBFT_DIR) -lft 
GNLFLAGS  =     -L ./$(GNL_DIR) -lget_next_line
LMLXFLAGS =		-L ./$(MLX_DIR)	-lmlx_Linux -I minilibx-linux -lXext -lX11 -lm -lz
RM        =     /bin/rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(GNL) $(LMLX)
		@$(CC) $(OBJ) $(HEAD) $(FLAGS) $(LFLAGS) $(GNLFLAGS) $(LMLXFLAGS) -o $(NAME)

bonus: $(NAMEBONUS)

$(NAMEBONUS): $(LIBFT) $(OBJBONUS) $(GNL) $(LMLX)
		@$(CC) $(OBJBONUS) $(HEAD) $(FLAGS) $(LFLAGS) $(GNLFLAGS) $(LMLXFLAGS) -o $(NAMEBONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(FLAGS) $(HEAD) -c $< -o $@
		@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

$(OBJ_DIRB)/%.o: $(SRC_DIRB)/%.c 
		@mkdir -p $(OBJ_DIRB)
		@$(CC) $(FLAGS) $(HEAD) -c $< -o $@
		@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

$(LIBFT):
		@make -C $(LIBFT_DIR)
		@make -C $(GNL_DIR)
		@make -sC $(MLX_DIR)

clean:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(GNL_DIR)
		@$(RM) $(OBJ_DIR)

cleanbonus:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(GNL_DIR)
		@$(RM) $(OBJ_DIRB)

fclean:	clean
		@make fclean -C $(LIBFT_DIR)
		@make fclean -C $(GNL_DIR)
		@make clean -C $(MLX_DIR)
		@$(RM) $(NAME)

fcleanbonus: cleanbonus
		@make fclean -C $(LIBFT_DIR)
		@make fclean -C $(GNL_DIR)
		@make clean -C $(MLX_DIR)
		@$(RM) $(NAMEBONUS)

re:		fclean all

rebonus:	fcleanbonus bonus

.PHONY:	re fclean clean all bonus cleanbonus fcleanbonus
