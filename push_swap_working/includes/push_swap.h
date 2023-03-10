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
int		int_max_check(char *str_num, int *number);

//	ps_utils_t_list_ops.c
int		t_list_ops_add(t_list **ops, char *content);

//	ps_algo_1.c
int		sort_two_ops(t_list **a, t_list **ops,
			int (*op1)(t_list **, t_list **),
			int (*op2)(t_list **, t_list **));
int		sort_three(t_list **a, t_list **ops);
int		sort_le_three(t_list **a, t_list **ops, int size);
int		sort_entry(t_list **a);

//	ps_algo_2.c
int		sort_placement(t_list **lst_from, t_list **lst_to, t_list **ops);
int		sort_le_five(t_list **a, t_list **b, t_list **ops, int size);

//	ps_lst_1.c
t_list	*ft_lstcmpsm(t_list *l1, t_list *l2);
t_list	*ft_lstcmpbg(t_list *l1, t_list *l2);
t_list	*ft_lstseek_a(t_list *l1, t_list *l2,
			t_list *(*op)(t_list *, t_list *));
int		ft_lstseek_i(t_list *l1, t_list *l2,
			t_list *(*op)(t_list *, t_list *));

//	ps_ops_1.c
int		sa(t_list **a, t_list **ops);
int		ra(t_list **a, t_list **ops);
int		rra(t_list **a, t_list **ops);

//	ps_ops_2.c
int		sb(t_list **b, t_list **ops);
int		rb(t_list **b, t_list **ops);
int		rrb(t_list **b, t_list **ops);

//	ps_ops_3.c
int		pa(t_list **a, t_list **b, t_list **ops);
int		pb(t_list **a, t_list **b, t_list **ops);
int		ss(t_list **a, t_list **b, t_list **ops);
int		rr(t_list **a, t_list **b, t_list **ops);
int		rrr(t_list **a, t_list **b, t_list **ops);

//	ps_debug_tools.c
void	t_list_print_int(int i, t_list *current, char h_flag);
void	t_list_print_str(int i, t_list *current, char h_flag);
void	t_list_print(t_list *start, void (*ptype)(int, t_list *,
				char), char h_flag);
void	table_print(char **table);

#endif
