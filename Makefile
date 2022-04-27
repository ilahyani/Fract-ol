MANDELBROT_SRCS	=	Mandelbrot.c\
					utils.c

JULIA_SRCS	=	Julia.c\
				utils.c

HDR	= fractol.h

LIBFT = ./libft

LIB = ./libft/libft.a

Mandelbrot:	$(LIB) $(HDR)
			gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit $(MANDELBROT_SRCS) $(LIB) -o Mandelbrot

Julia:	$(LIB) $(HDR)
		gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit $(JULIA_SRCS) $(LIB) -o Julia

all:  $(LIB)
		gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit $(SRCS) $(LIB) -o fractol

$(LIB):
			Make -C $(LIBFT)

clean:	
		rm -rf fractol $(LIBFT)/*.o $(LIBFT)/ft_printf/*.o

fclean:	clean
		rm -rf *.o $(LIB)

re:	fclean all