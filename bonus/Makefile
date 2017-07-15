##
## Makefile for  in /home/Wasx/CPool_Day12
## 
## Made by Wassim ALKAYAR
## Login   <Wasx@epitech.net>
## 
## Started on  Wed Mar 15 10:16:14 2017 Wassim ALKAYAR
## Last update Sun Jun 11 21:52:13 2017 Wassim Alkayar
##

NAME	=	wolf3d

SRC	=	main.c				\
		src/my_put_pixel.c		\
		src/my_draw_line.c		\
		src2/change_color.c		\
		src2/create_pixel_buffer.c	\
		src2/create_window.c		\
		src2/strlen.c			\
		src2/getfile.c			\
		src2/maintainwindow.c		\
		src2/closewindow.c		\
		src2/clearbuffer.c		\
		src2/draw_line_custom.c		\
		src2/game.c			\
		src2/gametwo.c			\
		src2/keyboard.c

OBJ	=	$(SRC:.c=.o)

GCC	=	gcc -lm -lcsfml-window -lcsfml-graphics -lcsfml-audio

CFLAGS	=	-O3 -g3 -Wextra -Wall

CPPFLAGS=	-I./include

RM	=	rm -f

ASUPR2	=	wolf3d

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(ASUPR2)

re:	fclean all

.PHONY: all clean fclean re
