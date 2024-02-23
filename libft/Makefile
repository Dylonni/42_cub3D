# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mba <mba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:37:09 by mba               #+#    #+#              #
#    Updated: 2023/12/27 12:54:34 by mba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS         = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
               ft_tolower.c ft_atoi.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c  ft_strlen.c \
               ft_strchr.c ft_strrchr.c ft_strnstr.c ft_bzero.c *ft_memset.c ft_memcpy.c \
               ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c *ft_substr.c ft_memmove.c\
	           ft_strjoin.c ft_split.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
	           ft_putnbr_fd.c ft_putendl_fd.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_putstr.c \
			   get_next_line.c gnl_utils.c

B_SRCS	 	 = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c\
			   ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = ${SRCS:.c=.o}

B_OBJS = ${B_SRCS:.c=.o}

NAME         = libft.a 


CC		= gcc
RM		= rm -f
AR		= ar rc
RN		= ranlib

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} 
		${AR} ${NAME} ${OBJS}
		${RN} ${NAME}

bonus:	${B_OBJS} 
		${AR} ${NAME} ${B_OBJS}
		${RN} ${NAME}

all:	${NAME} 

clean:
		${RM} ${OBJS} ${B_OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
