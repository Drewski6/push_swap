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

BONUS = checker

# ***** Sources *****

SRCS_MAN = push_swap.c

SRCS = ps_switch.c \
	ps_utils_args.c \
	ps_utils_t_list_1.c \
	ps_utils_t_list_2.c \
	ps_utils_t_list_ops_1.c \
	ps_utils_t_list_ops_2.c \
	ps_algo_1.c \
	ps_algo_2.c \
	ps_algo_3.c \
	ps_algo_rough_2.c \
	ps_algo_rough_3.c \
	ps_algo_rough_1.c \
	ps_algo_fine_1.c \
	ps_algo_fine_2.c \
	ps_lst_1.c \
	ps_ops_1.c \
	ps_ops_2.c \
	ps_ops_3.c \
	ps_debug_tools_1.c \
	ps_debug_tools_2.c \

SRCS_DIR = srcs/

BONUS_SRCS = checker.c \

BONUS_SRCS_DIR = bonus/srcs/

# ***** Includes *****

INCS = push_swap.h \
		push_swap_bonus.h \

INCS_DIR = includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_MAN = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_MAN))

OBJS_DIR = objs/

BONUS_OBJS = $(patsubst %.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS))

BONUS_OBJS_DIR = bonus/objs/

# ***** Compile and Archiver *****
# Variables for testing best chunk size.

BCC=16
SCC=6
SAC=10

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

LIBFT = -Llibft -lft

# ***** Build *****

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(OBJS_MAN)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_MAN) $(LIBFT) -o $(NAME)

$(BONUS): $(OBJS) $(BONUS_OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) -c $(CFLAGS) -I$(INCS_DIR) $< -o $@

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
	@mkdir -p $(BONUS_OBJS_DIR)
	$(CC) -c $(CFLAGS) -I$(INCS_DIR) $< -o $@

clean:
	@make -C libft clean --silent
	@rm -f $(OBJS)
	@rm -f $(OBJS_MAN)
	@rm -f $(BONUS_OBJS)

fclean:	clean
	@make -C libft fclean --silent
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@rm -f gdb.txt

re:	fclean all
