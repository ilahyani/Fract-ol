# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 22:30:48 by ilahyani          #+#    #+#              #
#    Updated: 2022/04/28 06:48:07 by ilahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Mandelbrot.c\
			Julia.c\
			Multibrot.c\
			utils.c\
			main.c

NAME	=	fractol

HDR	= ./fractol.h

LIBFT = ./libft

LIB = ./libft/libft.a

all:  $(NAME)

$(NAME):	$(SRCS) $(LIB) $(HDR)
			gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit $(SRCS) $(LIB) -o $(NAME)

$(LIB):
			Make -C $(LIBFT)

%.o: %.c $(HDR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:	
		rm -rf fractol $(LIBFT)/*.o $(LIBFT)/ft_printf/*.o

fclean:	clean
		rm -rf *.o $(LIB)

re:	fclean all
