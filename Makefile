NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL -g 
SRCS =  main.c error.c flood_fill.c map_check.c map_name.c map_print.c create_map.c keycode.c error2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_printf2.c

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a

all: ${NAME}

$(MINI):
	make -C ./mlx &> /dev/null

$(NAME): $(MINI) $(OBJS) 
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME) 

%.o: %.c
	${CC} -c $^ -o $@ -Wall -Werror -Wextra 

clean:
	rm -rf ${OBJS}
	make clean -C mlx/

fclean: clean
	rm -rf ${NAME}
	make clean -C mlx/

re: fclean all

.PHONY: fclean re all clean