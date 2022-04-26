SRCS	=	main.c\
			Mandelbrot.c\
			utils.c

all:  
		gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit $(SRCS) -o fractol

clean:	
		rm -rf fractol

fclean:	clean
		rm -rf *.o

re:	fclean all