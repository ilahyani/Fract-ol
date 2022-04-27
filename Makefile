SRCS	=	main.c\
			Mandelbrot.c\
			utils.c

LIBFT = ./libft

LIB = ./libft/libft.a

all:  $(LIB)
		gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit $(SRCS) $(LIB) -o fractol

$(LIB):
			Make -C $(LIBFT)

clean:	
		rm -rf fractol $(LIBFT)/*.o $(LIBFT)/ft_printf/*.o

fclean:	clean
		rm -rf *.o $(LIB)

re:	fclean all