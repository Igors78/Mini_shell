# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 18:24:26 by ioleinik          #+#    #+#              #
#    Updated: 2021/10/17 15:38:15 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= minishell

LIB_PATH	= ./libft

LIBRARY		= libft.a

MAKE		= make

SRC			= 	main.c		execute.c				export.c		util.c \
				exp_arg.c	signal.c 				init.c			parse_split.c \
			check_io.c	check_redirection.c		check_x.c		check_line.c \
			ft_getenv.c	expand_env.c 			check_path.c 	is_builtin.c \
			cmd_x.c		cmd_out.c \
			pipe.c		error.c							

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