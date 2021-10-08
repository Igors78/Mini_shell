# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 18:24:26 by ioleinik          #+#    #+#              #
#    Updated: 2021/10/08 13:51:07 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= minishell

LIB_PATH	= ./libft

LIBRARY		= libft.a

MAKE		= make

SRC			= main.c execute.c interpret.c util.c

OBJ			= ${SRC:.c=.o}

LINKS		= -I$(LIB_PATH) \
			-L$(LIB_PATH) \
			-lft \
			-lreadline

all:		$(LIBRARY) $(NAME)


$(LIBRARY):
			$(MAKE) -C $(LIB_PATH)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LINKS) 

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIB_PATH) fclean

re:			fclean all
#Command runs norminette only for my files
norm:
			norminette libft/
			norminette $(SRC) || true

.PHONY: all clean fclean re norm