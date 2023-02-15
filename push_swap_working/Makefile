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

# ***** Sources *****

SRCS = push_swap.c \
	ps_utils_args.c \
	ps_utils_t_list_1.c \
	ps_utils_t_list_2.c \
	ps_ops_1.c \
	ps_debug_tools.c \

SRCS_DIR = srcs/

# ***** Includes *****

INCS = push_swap.h

INCS_DIR = includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_DIR = objs/

# ***** Compile and Archiver *****

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

LIBFT = -Llibft -lft

# ***** Build *****

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) -c $(CFLAGS) -I$(INCS_DIR) $< -o $@

clean:
	@make -C libft clean --silent
	@rm -f $(OBJS)

fclean:	clean
	@make -C libft fclean --silent
	@rm -f $(NAME)

re:	fclean all
