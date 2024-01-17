/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:19:23 by lseghier          #+#    #+#             */
/*   Updated: 2023/12/17 01:39:51 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*pushed;

	if (!(*a))
		return ;
	pushed = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	pushed->prev = NULL;
	if (!*b)
	{
		*b = pushed;
		(*b)->next = NULL;
	}
	else
	{
		pushed->next = *b;
		pushed->next->prev = pushed;
		*b = pushed;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(a, b);
	write(1, "pb\n", 3);
}
