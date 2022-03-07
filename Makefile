# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CC				=	gcc
RM				=	rm -rf
AR				=	ar rcs

# **************************************************************************** #
#       TITLE                                                                  #
# **************************************************************************** #
NAME			=	cub3D

# **************************************************************************** #
#       FLAGS                                                                  #
# **************************************************************************** #
OS				=	$(shell uname)
CFLAGS			=	-Wall -Wextra -Werror
FSAN			=	-fsanitize=address
DEBUG			=	-g3

ifeq ($(OS), Linux)
MLX_FLAGS		+=	-Lmlx -lmlx -lbsd -lXext -lX11 -lm
else
MLX_FLAGS		+=	-Lmlx -lmlx -framework OpenGL -framework AppKit
endif

# **************************************************************************** #
#       SOURCES                                                                #
# **************************************************************************** #
SRCS_DIR		=	srcs
INCS_DIR		=	incs

SRCS			=	main.c \
					utils/ft_return.c \
					utils/ft_free_cub3d.c \
					parser/ft_parser.c \
					parser/ft_get_info.c \
					parser/ft_check_info.c \
					parser/ft_get_map.c \
					parser/ft_check_map.c \
					parser/ft_set_player.c \
					events/ft_close.c \
					events/ft_key_event.c \
					debug/ft_print_struct.c \

INCS			=	cub3d.h \

# **************************************************************************** #
#       LIBRARIES                                                              #
# **************************************************************************** #
LIBFT_A			=	libft.a
LIBFT_DIR		=	libft

LIBMLX_A		=	libmlx.a
LIBMLX_DIR		=	mlx

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS			=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o				:	%.c
					$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

ifeq ($(OS), Linux)
$(NAME)			:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
					$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(MLX_FLAGS)
else
$(NAME)			:	$(OBJS) $(LIBFT_A)
					$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(MLX_FLAGS)
endif

$(LIBFT_A)		:
					make -C $(LIBFT_DIR) $(LIBFT_FLAGS)
					mv $(LIBFT_DIR)/$(LIBFT_A) .

$(LIBMLX_A)		:
					make -C $(LIBMLX_DIR) $(MLX_FLAGS)

all				:	$(NAME)

clean			:
					$(RM) $(OBJS) $(LIBFT_A)
					make clean -C $(LIBFT_DIR)
					make clean -C $(LIBMLX_DIR)

fclean			:	clean
					$(RM) $(NAME)
					make fclean -C $(LIBFT_DIR)


re				:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY			:	all bonus clean fclean re
