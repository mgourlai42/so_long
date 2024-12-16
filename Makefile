# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 03:00:05 by mgourlai          #+#    #+#              #
#    Updated: 2023/06/16 14:27:20 by mgourlai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC	= gcc
RM	= rm -rf
CFLAGS	= -Wall -Wextra -Werror
#DEBUG	= -g3 -fsanitize=address

SRCS	= game/main.c \
	game/countlines.c \
	game/graphic.c \
	game/display.c \
	game/events.c \
	game/enemy.c \
	game/maps.c \
	game/mapchecking.c \
	game/mapchecking2.c \
	game/mapchecking3.c \
	Get_Next_Line_Mod/get_next_line_bonus.c \
	Get_Next_Line_Mod/get_next_line_utils_bonus.c \
	
OBJS	= $(SRCS:.c=.o)
	
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	make all -C libft
	$(CC) $(OBJS) ./libft/libft.a ./minilibx-linux/libmlx_Linux.a $(DEBUG) -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all
	
.PHONY:all, clean, fclean, re
