NAME = so_long

SRC_FILES = utils.c arg_validation.c map_parsing.c checking_walls.c open_map.c main.c

SRCS = $(addprefix ./sources/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I ./includes -I ./libft  $(OBJS) -L ./libft -lft -o $(NAME)

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
