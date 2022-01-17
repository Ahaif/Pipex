# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 10:20:05 by ahaifoul          #+#    #+#              #
#    Updated: 2021/12/15 13:14:18 by ahaifoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_split.c ft_strnstr.c ft_strjoin.c ft_substr.c ft_strlcpy.c ft_strlen.c


OBJS :=$(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $@ $^

%.o: %.c
	gcc -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJB)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
