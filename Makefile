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

SRC				=	builtin.c\
					enhanced_split.c\
					exec_prog.c\
					main.c\
					sign_handle.c\
					split_semi_colon.c\
					handle_env.c\
					get_next_line.c\
					get_next_line_utils.c\

SRCD			= ./srcs/

ROAD_S			= $(addprefix $(SRCD), $(SRC))

ROAD_O			= $(OBJ)

OBJ				= $(ROAD_S:.s=.o)

CC				= clang

FLAGS			= -Werror -Wall -Wextra

HEADER_DIR		= -I./head/get_next_line.h -I./head/minishell.h 

$(NAME) :
				cd libft && make
				$(CC) $(FLAGS) $(OBJ) libft/libft.a
				mv a.out minishell


all :			$(NAME)

clean :
				rm -f $(ROAD_O)

fclean : clean
				rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
