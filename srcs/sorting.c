/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 01:38:08 by lseghier          #+#    #+#             */
/*   Updated: 2023/12/17 01:46:09 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_all(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	current_pos(*a);
	current_pos(*b);
}

void	reverse_rotate_all(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	current_pos(*a);
	current_pos(*b);
}

void	rotation(t_stack **a, t_stack *cell, int id)
{
	while (*a != cell)
	{
		if (id)
		{
			if (cell->upper_half)
				ra(a);
			else
				rra(a);
		}
		else
		{
			if (cell->upper_half)
				rb(a);
			else
				rrb(a);
		}
	}
}

void	put_right_place(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->upper_half && cheapest->target->upper_half)
		rotate_all(a, b, cheapest);
	else if (!(cheapest->upper_half) && !(cheapest->target->upper_half))
		reverse_rotate_all(a, b, cheapest);
	rotation(a, cheapest->target, 1);
	rotation(b, cheapest, 0);
	pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len;

	len = lenstack(*a);
	while (len-- > 3)
		pb(b, a);
	tiny_sort(a);
	while (*b)
	{
		set_params(*a, *b);
		put_right_place(a, b);
	}
	smallest = find_smallest(*a);
	if (smallest->upper_half)
	{
		while (*a != smallest)
			ra(a);
	}
	else
	{
		while (*a != smallest)
			rra(a);
	}
}
