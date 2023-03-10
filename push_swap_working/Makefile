# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 14:27:11 by dpentlan          #+#    #+#              #
#    Updated: 2023/01/30 14:27:14 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \

SRCS_DIR = srcs/

HEADERS_DIR = includes/

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_DIR = objs/

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) -c $(CFLAGS) -I$(HEADERS_DIR) $< -o $@

clean:
	rm -f $(OBJS)


fclean:	clean
	rm -f $(NAME)

re:	fclean all
