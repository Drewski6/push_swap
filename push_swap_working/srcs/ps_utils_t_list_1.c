/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_t_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:35:48 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/14 11:35:52 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** t_list_dup_check (list duplicate content check) ***
 *
 *	Iterates over a list and compares the content to 'new_value'.
 *	If a match is found, there is a duplicate value.
 *	Takes t_list pointer to beginning of the list 'start' and an integer
 *	value 'new_value' to compare the content to.
 *	Returns 0 if no duplicates are found and -1 if duplicate value.
 */

int	t_list_dup_check(t_list *start, int new_value)
{
	t_list	*current;

	current = start;
	while (current)
	{
		if (current->content == 0)
			return (-1);
		if (*(int *)(current->content) == new_value)
			return (-1);
		current = current->next;
	}
	return (0);
}

/*	*** t_list_add (type list (struct) add) ***
 *
 *	Adds a link to list 'a' with content 'content'.
 *	Checks for duplicates in the list and returns error if duplicates
 *	are found.
 *	Takes a pointer to list start 'a' and a pointer to integer 'content'.
 *	Returns 0 on success and -1 on ERROR.
 */

int	t_list_add(t_list **a, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
	{
		free(content);
		ft_lstclear(a, &t_list_free_content);
		return (-1);
	}
	if (ft_lstsize(*a) == 0)
		*a = new;
	else
	{
		if (t_list_dup_check(*a, *(int *)new->content) < 0)
		{
			ft_lstclear(&new, &t_list_free_content);
			return (-1);
		}
		ft_lstadd_back(a, new);
	}
	return (0);
}

/*	*** t_list_alloc_content (list content) ***
 *
 *	Allocates memory for 1 integer value to be used as content in t_list
 *	Takes an integer value 'number'.
 *	Returns a pointer to a heap allocated address space containing 'number'.
 */

int	*t_list_alloc_content(int number)
{
	int	*pnumber;

	pnumber = (int *)malloc(1 * sizeof(int));
	if (!pnumber)
		return (0);
	*pnumber = number;
	return (pnumber);
}

/*	*** t_list_atoi_wrapper (type list (struct) ascii to integer wrapper) ***
 *
 *	Does additional error checking for ft_atoi for push_swap program.
 *	Checks for multiple signs and makes sure at least 1 character is a digit.
 *	Takes a string to check 'str_num'.
 *	Returns 0 on success or -1 on ERROR.
 */

int	t_list_atoi_wrapper(char *str_num, int *number)
{
	int	i;
	int	signs;
	int	digit;

	i = 0;
	signs = 0;
	digit = 0;
	while (str_num[i])
	{
		if (str_num[i] == '-' || str_num[i] == '+')
			signs++;
		if (ft_strchr("0123456789", str_num[i]))
			digit = 1;
		i++;
	}
	if (signs > 1 || digit == 0)
		return (-1);
	*number = ft_atoi(str_num);
	return (0);
}

/*	*** t_list_construct (type list (struct) construct)***
 *
 *	Creates a list of t_list structs while checking for duplicate values.
 *	Takes a table of strings (which should only contain digits) 'table'.
 *	Returns a pointer to a new t_list struct 'a'.
 */

t_list	*t_list_construct(char **table)
{
	int		i;
	t_list	*a;
	int		*content;
	int		num;
	int		ret;

	i = 0;
	a = 0;
	while (table[i])
	{
		content = 0;
		ret = t_list_atoi_wrapper(table[i], &num);
		if (ret >= 0)
			content = t_list_alloc_content(num);
		if (content)
			ret = t_list_add(&a, content);
		if (ret < 0 || !content)
		{
			ft_lstclear(&a, &t_list_free_content);
			return (0);
		}
		i++;
	}
	return (a);
}
