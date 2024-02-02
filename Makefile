# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:51:42 by ohosnedl          #+#    #+#              #
#    Updated: 2024/01/29 15:52:01 by ohosnedl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
CFLAGS	:= -Wextra -Wall -Werror -g -pthread
SRCS	:= $(wildcard *.c)
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

bonus: all

re: clean all

.PHONY: all, clean, fclean, re, bonus
