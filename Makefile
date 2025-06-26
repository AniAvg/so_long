NAME = so_long

SRC_FILES = utils.c free.c arg_validation.c map_validation.c checking_walls.c \
			check_reachability.c validation.c load_textures.c make_window.c \
			movement.c animation.c main.c

SRCS = $(addprefix ./sources/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS	= -Lmlx -lmlx -lXext -lX11 -lm

LIBFT = ./libft/libft.a

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I ./includes -I ./libft  $(OBJS) $(MLX_FLAGS) -L ./libft -lft -o $(NAME)

$(LIBFT) :
	make -C ./libft all

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -I./libft -c -o $@ $<

clean :
	make -C ./libft clean
	rm -f $(OBJS)

fclean : clean
	make -C ./libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
