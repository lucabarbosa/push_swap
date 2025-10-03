# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbento <lbento@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 18:22:14 by lbento            #+#    #+#              #
#    Updated: 2025/09/08 22:06:25 by lbento           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CPPFLAGS = -I.
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c \
	ft_isdigit.c  \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c

OBJS = $(SRCS:.c=.o)

BONUS_SRC = ft_lstnew_bonus.c \
	    ft_lstadd_front_bonus.c \
	    ft_lstsize_bonus.c \
	    ft_lstlast_bonus.c \
	    ft_lstadd_back_bonus.c \
	    ft_lstdelone_bonus.c \
	    ft_lstclear_bonus.c \
	    ft_lstiter_bonus.c \
	    ft_lstmap_bonus.c

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:
	@$(MAKE) OBJS="$(OBJS) $(BONUS_OBJS)"

$.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
