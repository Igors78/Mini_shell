# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 18:24:26 by ioleinik          #+#    #+#              #
#    Updated: 2021/10/30 15:24:51 by mbarut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= minishell

LIB_PATH	= ./libft

SRC_PATH	= ./src

INC_PATH	= ./include

LIBRARY		= libft.a

MAKE		= make

SRC			= 	main.c			execute.c		export.c		util.c \
				exp_arg.c		signal.c 		init.c			parse_split.c \
				handle_input.c	handle_output.c	handle_fork.c	handle_pipe.c \
				handle_exec.c	handle_builtins.c 				handle_comments.c \
				check_path.c	is_builtin.c	is_forkable.c	ft_split_utils.c\
				ft_getenv.c		expand_env.c	pipe.c			error.c	\
				check_env.c		parse_env.c		ft_builtins.c \
				handle_buck.c	ft_builtin_util.c				handle_input_util.c \
				handle_output_util.c			skip_to_executable.c

OBJ			= $(addprefix $(SRC_PATH)/, $(SRC:.c=.o))

LINKS		= -I$(LIB_PATH) \
			-L$(LIB_PATH) \
			-I$(INC_PATH) \
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

.PHONY: all clean fclean re norm