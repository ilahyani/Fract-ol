all:  
		gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit main.c -o fractol

clean:	
		rm -rf fractol

fclean:	clean
		rm -rf *.o

re:	fclean all