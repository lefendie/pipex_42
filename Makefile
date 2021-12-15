# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lefendie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 14:29:06 by lefendie          #+#    #+#              #
#    Updated: 2021/12/15 11:38:58 by lefendie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= pipex

LIBFT_A = libft/libft.a

MAIN := main.c

OBJ_MAIN := $(MAIN:.c=.o)

SRC		:= src/tools.c src/redirection.c src/pipe.c

OBJ		:= $(SRC:.c=.o)

OBJ_WITH_MAIN:= $(OBJ) ${OBJ_MAIN} ${LIBFT_A}

MAIN_BONUS := main_bonus.c

OBJ_MAIN_BONUS := $(MAIN_BONUS:.c=.o)

SRC_BONUS		:= 	src/tools.c src/redirection.c src/redirection_bonus.c \
								src/pipe.c src/pipe_bonus.c src/get_next_line.c

OBJ_BONUS		:= $(SRC_BONUS:.c=.o)

OBJ_WITH_MAIN_BONUS := $(OBJ_BONUS) ${OBJ_MAIN_BONUS} ${LIBFT_A}

%.o: %.c; ${CC} ${CFLAGS} -o $@ -c $<

RM	= /bin/rm -rf

CC	= clang

CFLAGS	= -Wall -Wextra -Werror -Ilibft/include -Iinclude -g3

LIB = -Llibft -lft

${NAME}:  ${OBJ_WITH_MAIN}
	${CC} ${OBJ_WITH_MAIN} -o ${NAME} ${LIB}

${LIBFT_A}:
	make -s -C libft

all: ${NAME} 

bonus: ${OBJ_WITH_MAIN_BONUS}
	${CC} ${OBJ_WITH_MAIN_BONUS} -o ${NAME} ${LIB}
	
clean:
	${RM} ${OBJ_WITH_MAIN} ${OBJ_WITH_MAIN_BONUS} libft/libft.a main.o

fclean:	clean
	${RM} ${NAME}

re:	fclean clean all

.PHONY: re clean fclean all bonus
