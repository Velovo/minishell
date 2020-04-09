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

NAME			= libft.a

NAMED			= bonus.a

SRC				=	ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_memccpy.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_memset.c\
					ft_putchar_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					ft_putstr_fd.c\
					ft_split.c\
					ft_strchr.c\
					ft_strdup.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strmapi.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_tolower.c\
					ft_toupper.c\

SRCB			=	ft_lstadd_back_bonus.c\
					ft_lstadd_front_bonus.c\
					ft_lstclear_bonus.c\
					ft_lstdelone_bonus.c\
					ft_lstiter_bonus.c\
					ft_lstlast_bonus.c\
					ft_lstmap_bonus.c\
					ft_lstnew_bonus.c\
					ft_lstsize_bonus.c\

ROAD_S			= $(SRC)

ROAD_O			= $(OBJ)

ROAD_B			= $(SRCB)

ROAD_N			= $(OBJ2)

FLAGS			= -Wall -Wextra -Werror

OBJ				= $(SRC:.c=.o)

OBJ2			= $(SRCB:.c=.o)

CC				= clang

HEADER_DIR		= libft.h

$(NAME) :			$(OBJ)
				ar rc $(NAME) $(OBJ)

all :			$(NAME)

clean :
				rm -f $(ROAD_O)
				rm -f $(ROAD_N)

fclean : clean
				rm -f $(NAME)

re : fclean all

bonus:			$(OBJ2) $(OBJ)
				ar rc $(NAME) $(OBJ) $(OBJ2)

.PHONY: all clean fclean re bonus
