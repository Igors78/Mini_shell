# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 18:13:08 by ioleinik          #+#    #+#              #
#    Updated: 2021/07/27 10:04:04 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

AR		= ar rcs
RM		= rm -f

NAME	= libft.a
INCL	= libft.h

SRC		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_putchar.c \
			ft_putstr.c ft_printf.c dispatch.c handle_d.c ft_putnbr_base.c handle_c.c \
			handle_s.c handle_p.c handle_u.c handle_x.c handle_bigx.c \
			handle_perc.c init_table.c reset_table.c parse.c read_flags.c \
			handle_spec.c handle_spec_u.c handle_spec_x.c handle_spec_bigx.c \
			handle_spec_c.c handle_spec_p.c handle_precis.c ft_memdel.c ft_strnew.c \
			get_next_line.c ft_striteri.c ft_wordcount.c ft_terror.c ft_straddchar.c \
			ft_atoi_base.c

OBJ		= ${SRC:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

clean:		
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus