NAME		= so_long
BNAME		= so_long_bonus
INC			= inc
HEADER		= -I inc
LIBFT		= libft/
SRC_DIR		= src/
MLX			= mlx/
MLXCC		=	-L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ		= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
LEAKS	= -fsanitize=address
RM			= rm -f

GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
WHITE		=	\033[0;97m

MAN_DIR		=	mandatory/
MAN_FILES	=	map_check image_load window_load keyhook\
				map_load animate so_long

SRC_FILES	=	$(addprefix $(MAN_DIR), $(MAN_FILES))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

start:
			@echo "$(YELLOW)Start Make:$(WHITE)"
			@make all

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@make -C $(MLX)
			@$(CC) $(CFLAGS) $(OBJ) $(HEADER) libft.a $(MLXCC) -o $(NAME) 
			@echo "$(GREEN)so_long Done!$(WHITE)"

%.o: %.c
			@$(CC) $(CFLAGS) $(HEADER) -Imlx -c $< -o $@

clean:
			@$(RM) $(OBJ)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)so_long: object files have been cleaned!$(WHITE)"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) libft.a
			@$(RM) $(LIBFT)/libft.a
			@make clean -C $(MLX)
			@echo "$(BLUE)Libft: files have been cleaned!$(WHITE)"
			@echo "$(BLUE)so_long: files have been cleaned!$(WHITE)"
			@echo "$(BLUE)mlx: files have been cleaned!$(WHITE)"


re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for so_long\n$(WHITE)"

.PHONY:		all clean fclean re