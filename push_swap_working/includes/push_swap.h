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

//	push_swap.c
int		error(void);
t_list	*arg_switch(t_list *a, int argc, char **argv);
//	int main (int argc, char **argv);

//	ps_utils_args.c
void	table_free(char **table);
int		table_err_check(char **table);
char	**table_dup(char **table);
t_list	*m_arg_parse(char **s_table);
t_list	*s_arg_parse(char *s);

//	ps_utils_t_list_1.c
int		t_list_dup_check(t_list *start, int new_value);
int		t_list_add(t_list **a, void *content);
int		*t_list_alloc_content(int number);
int		t_list_atoi_wrapper(char *str_num, int *number);
t_list	*t_list_construct(char **table);

//	ps_utils_t_list_2.c
void	t_list_free_content(void *content);

//	ps_utils_t_list_ops.c
int		t_list_ops_add(t_list **ops, char *content);

//	ps_algo_1.c
int		sort_le_three(t_list **a, t_list **ops, int size);
int		sort_entry(t_list **a);

//	ps_ops_1.c
int		sa(t_list **a, t_list **ops);

//	ps_debug_tools.c
void	t_list_print_int(int i, t_list *current, char h_flag);
void	t_list_print_str(int i, t_list *current, char h_flag);
void	t_list_print(t_list *start, void (*ptype)(int, t_list *,
				char), char h_flag);
void	table_print(char **table);

#endif
