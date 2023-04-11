/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:44:49 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/10 16:45:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"

//	psb_verify_stack.c
int	psb_check_sort(t_list **a, t_list **b);
int	psb_read_inst(t_list **a, t_list **b);
int	psb_exec_inst(t_list **a, t_list **b, t_list **ops);

//	psb_ops_1.c
int	sa_checker(t_list **a, t_list **b);
int	ra_checker(t_list **a, t_list **b);
int	rra_checker(t_list **a, t_list **b);

//	psb_ops_2.c
int	sb_checker(t_list **a, t_list **b);
int	rb_checker(t_list **a, t_list **b);
int	rrb_checker(t_list **a, t_list **b);

//	psb_ops_3.c
int	pa_checker(t_list **a, t_list **b);
int	pb_checker(t_list **a, t_list **b);
int	ss_checker(t_list **a, t_list **b);
int	rr_checker(t_list **a, t_list **b);
int	rrr_checker(t_list **a, t_list **b);

#endif
