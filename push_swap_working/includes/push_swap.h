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
//	int main (int argc, char **argv);

//	ps_switch.c
int		error(void);
t_list	*arg_switch(t_list *a, int argc, char **argv);

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

//	ps_utils_t_list_ops_1.c
int		t_list_ops_add(t_list **ops, char *content);

//	ps_utils_t_list_ops_2.c
int		ops_del_two_and_replace(t_list **head, char *content);
int		optimize_lst_ss(t_list **head);
int		optimize_lst_rr(t_list **head);
int		optimize_lst_rrr(t_list **head);
int		optimize_list_entry(t_list **ops);

//	ps_algo_1.c
int		sort_multi_ops(t_list **a, t_list **ops, int size, ...);
int		sort_three(t_list **a, t_list **ops);
int		sort_le_three(t_list **a, t_list **ops, int size, int stack);
int		sort_entry(t_list **a);

//	ps_algo_2.c
int		sort_cost(t_list **lst_dest, int current_val);
int		sort_placement_middle(t_list **lst_src, t_list **lst_dest,
			t_list **ops, int current_val);
int		sort_placement(t_list **lst_src, t_list **lst_dest, t_list **ops);
int		sort_le_five(t_list **a, t_list **b, t_list **ops, int size);

//	ps_algo_3.c
int		sort_is_sorted(t_list **lst);
int		sort_recenter_cost(t_list **lst_dest);
int		sort_recenter(t_list **a, t_list **ops);

//	ps_algo_rough_1.c
int		sort_move_chunk(t_list **a, t_list **b,
			t_list **ops, int *chunk_info);
int		get_chunk_info(t_list **a, int *chunk_info);
int		sort_chunk(t_list **a, t_list **b, t_list **ops,
			int *chunk_info);
int		sort_rough(t_list **a, t_list **b, t_list **ops);
int		sort_gt_five(t_list **a, t_list **b, t_list **ops);

//	ps_algo_rough_2.c
t_list	*ft_lstseek_a_by_i(t_list **lst, int index);
int		ft_lstdel_and_relink_by_index(t_list **lst, int index);
int		ft_lstseek_i_by_val(t_list *lst, int val);
t_list	*ft_lstsort(t_list *lst);

//	ps_algo_rough_3.c
t_list	*ft_lstdup_node(t_list *src);
t_list	*ft_lstdup_lst(t_list *lst_old);
int		sort_move_chunk_ext(t_list **a, t_list **b,
			t_list **ops);

//	ps_algo_fine_1.c
int		sort_top_three(t_list **a, t_list **ops);
int		check_post_push(t_list **a, t_list **ops);
int		push_direct_push_logic(t_list **a, t_list **b, int *value, int *cost);
int		push_direct(t_list **a, t_list **b, t_list **ops);
int		sort_fine(t_list **a, t_list **b, t_list **ops);

//	ps_algo_fine_2.c
int		sort_fine_cost(t_list **lst, int current_val);
int		find_next_biggest(t_list **lst, int value);
int		get_cost_value_info(t_list **lst, int *cost, int *value);

//	ps_lst_1.c
int		ft_lstcmplt(int cmp, int ref);
int		ft_lstcmpgt(int cmp, int ref);
int		ft_lstcmp(t_list *lst, int (*op)(int, int));
int		ft_lstseek_i(t_list *lst, int (*op)(int, int));

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

//	ps_debug_tools_1.c
void	t_list_print_int(int i, t_list *current, char h_flag);
void	t_list_print_str(int i, t_list *current, char h_flag);
void	t_list_print(t_list *start, void (*ptype)(int, t_list *,
				char), char h_flag);
void	table_print(char **table);

//	ps_debug_tools_2.c
void	ezprint(t_list **lst);
void	ezprstr(t_list **lst);
void	ezprstr_c(t_list **lst);
void	ft_lstcmp_test(t_list *a, t_list *b);

#endif
