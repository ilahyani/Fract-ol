# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 22:30:48 by ilahyani          #+#    #+#              #
#    Updated: 2022/04/28 18:59:26 by ilahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Mandelbrot.c\
			Julia.c\
			utils.c\
			utils_2.c\
			main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	fractol

BNS_SRCS	=	bonus/fractol_bonus.c\
				bonus/utils_bonus.c\
				bonus/utils_bonus_2.c\
				bonus/main_bonus.c

BNS_OBJS = $(BNS_SRCS:.c=.o)

BNS_NAME	=	fractol_bonus

HDR	= ./fractol.h

BNS_HDR = bonus/fractol_bonus.h

LIBFT = ./libft

LIB = ./libft/libft.a

all:  $(NAME)

$(NAME):	$(OBJS) $(LIB) $(HDR)
			gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit $(OBJS) $(LIB) -o $(NAME)

bonus:	$(BNS_NAME)

$(BNS_NAME):	$(BNS_OBJS) $(LIB) $(BNS_HDR)
				gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit $(BNS_OBJS) $(LIB) -o $(BNS_NAME)

$(LIB):
			Make -C $(LIBFT)

%.o: %.c $(HDR) $(BNS_HDR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:	
		rm -rf ./*.o $(LIBFT)/*.o $(LIBFT)/ft_printf/*.o bonus/*.o

fclean:	clean
		rm -rf $(NAME) $(BNS_NAME) $(LIB)

re:	fclean all
