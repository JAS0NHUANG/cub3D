# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CC				=	clang
RM				=	rm -rf
AR				=	ar rcs

# **************************************************************************** #
#       TITLE                                                                  #
# **************************************************************************** #
NAME			=	cub3D
BONUS			=	cub3D_bonus

# **************************************************************************** #
#       FLAGS                                                                  #
# **************************************************************************** #
OS				=	$(shell uname)
CFLAGS			=	-Wall -Wextra -Werror
FSAN			=	-fsanitize=address
DEBUG			=	-g3

ifeq ($(OS), Linux)
MLX_FLAGS		=	-Lmlx -lbsd -lXext -lX11 -lm
endif

# **************************************************************************** #
#       SOURCES                                                                #
# **************************************************************************** #
SRCS_DIR		=	srcs
INCS_DIR		=	incs

SRCS			=	main.c \
					parser/ft_parser.c \
					parser/ft_get_info.c \
					parser/ft_init_info.c \
					parser/ft_check_info.c \
					parser/ft_get_map.c \
					parser/ft_check_map.c \
					parser/ft_set_player.c \
					draw/ft_print_minimap.c \
					draw/ft_print_canvas.c \
					draw/ft_init_canvas.c \
					draw/texture.c \
					events/ft_close.c \
					events/ft_move.c \
					events/ft_key_event.c \
					utils/ft_return.c \
					utils/ft_free_cub3d.c \
					debug/ft_print_struct.c \

INCS			=	cub3d.h \

# **************************************************************************** #
#       LIBRARIES                                                              #
# **************************************************************************** #
LIBFT_A			=	libft.a
LIBFT_DIR		=	libft

ifeq ($(OS), Linux)
LIBMLX_A		=	libmlx.a
LIBMLX_DIR		=	mlx
else
LIBMLX_A		=	libmlx.dylib
LIBMLX_DIR		=	mlx_mac
endif

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS			=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o				:	%.c
					$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@ 

$(NAME)			:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
					$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(LIBMLX_A) $(MLX_FLAGS)

$(BONUS)		:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
					$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(LIBMLX_A) $(MLX_FLAGS)

$(LIBFT_A)		:
					make -C $(LIBFT_DIR) $(LIBFT_FLAGS)
					mv $(LIBFT_DIR)/$(LIBFT_A) .

$(LIBMLX_A)		:
					make -C $(LIBMLX_DIR)
					mv $(LIBMLX_DIR)/$(LIBMLX_A) .

all				:	$(NAME)

bonus			:	$(BONUS)

clean			:
					$(RM) $(OBJS) $(LIBFT_A)
					make clean -C $(LIBFT_DIR)
					make clean -C $(LIBMLX_DIR)

fclean			:	clean
					$(RM) $(NAME)
					$(RM) $(BONUS)
					$(RM) $(LIBFT_A)
					$(RM) $(LIBMLX_A)
					make fclean -C $(LIBFT_DIR)


re				:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY			:	all bonus clean fclean re
