SRC = main.c
SRC += ft_free.c
SRC += ft_get_map.c
SRC += ft_get_map_error.c
SRC += ft_init_struct.c
SRC += ft_construct_data.c
SRC += ft_mouve_player.c
SRC += ft_register_img.c

CC = gcc -Wall -Werror -Wextra -g

NAME = so_long.a

EXEC = so_long

INCLUDE = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

OBJ = $(SRC:.c=.o)

all : $(EXEC) 

$(EXEC) : $(NAME)
	ar rcs so_long.a $(OBJ)
	gcc -g -o so_long so_long.a $(INCLUDE) 

$(NAME) : $(OBJ) 
	make -C ./minilibx-linux
	make -C ./libft
	cp libft/libft.a .
	mv libft.a so_long.a

$(OBJS)	:
	$(CC)  -c $(SRC) $(INCLUDE) 
	
clean : 
	make clean -C ./minilibx-linux
	make clean -C ./libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ./libft
	rm -rf $(OBJ)
	rm -rf so_long so_long.a

re : fclean all 
	make fclean -C ./libft
	
run :
	./so_long map.ber
