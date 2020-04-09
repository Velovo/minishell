# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-pra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:02:37 by avan-pra          #+#    #+#              #
#    Updated: 2019/10/10 13:39:50 by avan-pra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

SRC				=	./srcs/builtin.c\
					./srcs/enhanced_split.c\
					./srcs/exec_prog.c\
					./srcs/main.c\
					./srcs/sign_handle.c\
					./srcs/split_semi_colon.c\
					./srcs/handle_env.c\
					./srcs/get_next_line.c\
					./srcs/get_next_line_utils.c\

ROAD_S			= $(SRC)

ROAD_O			= $(OBJ)

ROAD_B			= $(SRCB)

FLAGS			= -Wall -Wextra -Werror

OBJ				= $(SRC:.c=.o)

CC				= clang

HEADER_DIR		= -I./head/get_next_line.h -I./head/minishell.h 

$(NAME) :		$(OBJ)
				cd libft && make
				$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

LIBFT			= libft

all :			$(NAME)

clean :
				cd libft && make clean
				rm -f $(ROAD_O)

fclean :
				cd libft && make fclean
				rm -f $(ROAD_O)
				rm -f $(NAME)

re : 			fclean all

.PHONY: 		all clean fclean re
