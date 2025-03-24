# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 17:29:17 by mbounoui          #+#    #+#              #
#    Updated: 2024/11/11 08:31:27 by mbounoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAN_SRCS = ft_isalpha.c\
       ft_isdigit.c\
       ft_isalnum.c\
       ft_isascii.c\
       ft_isprint.c\
       ft_strlen.c\
       ft_bzero.c\
       ft_memcpy.c\
       ft_memcmp.c\
       ft_toupper.c\
       ft_tolower.c\
       ft_atoi.c\
       ft_strdup.c\
       ft_strncmp.c\
       ft_strchr.c\
       ft_strrchr.c\
       ft_memchr.c\
       ft_putstr_fd.c\
       ft_putchar_fd.c\
       ft_putnbr_fd.c\
       ft_putendl_fd.c\
       ft_memset.c\
       ft_strlcat.c\
       ft_strnstr.c\
       ft_calloc.c\
       ft_memmove.c\
       ft_strlcpy.c\
       ft_substr.c\
       ft_strjoin.c\
       ft_strtrim.c\
       ft_split.c\
       ft_itoa.c\
       ft_strmapi.c\
       ft_striteri.c\
       get_next_line.c

OBJ_SRCS = ft_lstnew_bonus.c\
       ft_lstadd_front_bonus.c\
       ft_lstadd_back_bonus.c\
       ft_lstsize_bonus.c\
       ft_lstlast_bonus.c\
       ft_lstdelone_bonus.c\
       ft_lstclear_bonus.c\
       ft_lstiter_bonus.c\
       ft_lstmap_bonus.c\

MAN_OBJS = $(MAN_SRCS:.c=.o)
BON_OBJS = $(OBJ_SRCS:.c=.o)

CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
AR = ar crs
NAME = libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(BON_OBJS) $(NAME)
	@$(AR) $(NAME) $(BON_OBJS)

#exec: $(NAME)
#	@$(CC) $(FLAGS) main.c -L. -lft -o program

$(NAME): $(MAN_OBJS)
	@$(AR) $(NAME) $(MAN_OBJS)

%.o: %.c libft.h
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(MAN_OBJS) $(BON_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
