/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:42:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/10 16:42:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	a = 0;
	if (argc == 1)
		return (0);
	a = arg_switch(a, argc, argv);
	if (!a)
	{
		error();
		return (-1);
	}
	psb_check_sort(&a);
	ft_lstclear(&a, &t_list_free_content);
	return (0);
}
