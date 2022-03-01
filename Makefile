# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CC			=	gcc
RM			=	rm -rf
AR			=	ar rcs

# **************************************************************************** #
#       TITLE                                                                  #
# **************************************************************************** #
NAME		=	cub3D

# **************************************************************************** #
#       FLAGS                                                                  #
# **************************************************************************** #
CFLAGS		=	-Wall -Wextra -Werror
READLINE	=	-lreadline
TERMCAP		=	-ltermcap
FSAN		=	-fsanitize=address
DEBUG		=	-g3
OS			=	$(shell uname)

ifeq ($(OS), Linux)
	MLX_FLAGS	=	-L mlx -l mlx -L /usr/lib -l Xext -l X11 -l m
else
	MLX_FLAGS	=	-L mlx -l mlx -framework OpenGL -framework AppKit
endif

# **************************************************************************** #
#       SOURCES                                                                #
# **************************************************************************** #
SRCS_DIR	=	srcs
INCS_DIR	=	incs

SRCS		=	main.c \
				ft_return.c \
				parser/ft_parser.c \
				parser/ft_get_info.c \
				parser/ft_check_info.c \
				parser/ft_get_map.c \
				parser/ft_check_map.c \
				debug/ft_print_struct.c \

INCS		=	cub3d.h \

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
OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o			:	%.c
			$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME)		:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
			$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(MLX_FLAGS) 

$(LIBFT_A)		:
					make -C $(LIBFT_DIR) $(LIBFT_FLAGS)
					mv $(LIBFT_DIR)/$(LIBFT_A) .

$(LIBMLX_A)		:
					make -C $(LIBMLX_DIR) $(MLX_FLAGS)

all			:	$(NAME)

clean		:
			$(RM) $(OBJS) $(LIBFT_A)
			make clean -C $(LIBFT_DIR)

fclean		:	clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT_DIR)

re			:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY		:	all bonus clean fclean re
