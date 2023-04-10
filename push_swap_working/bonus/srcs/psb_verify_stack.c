/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_verify_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:34:41 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/10 17:35:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 *
 *
 */

int	psb_check_sort(t_list **a)
{
	if (sort_is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
