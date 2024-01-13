NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL 
SRCS =  error.c flood_fill.c map_check.c map_name.c map_print.c create_map.c keycode.c

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a

all: ${NAME}

$(MINI):
	make -C ./mlx

$(NAME): $(MINI) $(OBJS) 
	$(CC) ${CFLAGS} $(OBJS) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -o $(NAME) 

%.o: %.c
	${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

clean:
	rm -rf ${OBJS}
	make clean -C mlx/

fclean: clean
	rm -rf ${NAME}
	make clean -C mlx/

re: fclean all
.PHONY: fclean re all clean