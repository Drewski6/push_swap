/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/01/30 14:38:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

typedef struct s_list {
	s_list	*next;
	int		value;
}				t_list;

//	push_swap.c
int	error();
t_list	*arg_switch(int argc, char **argv);

//	ps_utils_args.c
int	s_arg_parse(char *s);

//	ps_utils_t_list.c
t_list	*t_list_construct(char **table);

#endif
