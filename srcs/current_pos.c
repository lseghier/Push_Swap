/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:57:36 by lseghier          #+#    #+#             */
/*   Updated: 2023/12/17 01:52:46 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_pos(t_stack *a)
{
	int	i;
	int	center;

	i = 0;
	if (!a)
		return ;
	center = lenstack(a) / 2;
	while (a)
	{
		a->pos = i;
		if (i <= center)
			a->upper_half = 1;
		else
			a->upper_half = 0;
		a = a->next;
		i++;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*target;
	long	target_value;

	while (b)
	{
		target_value = LONG_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->value > b->value && tmp_a->value < target_value)
			{
				target_value = tmp_a->value;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (target_value == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = lenstack(a);
	len_b = lenstack(b);
	while (b)
	{
		b->price = b->pos;
		if (!(b->upper_half))
			b->price = len_b - b->pos;
		if (b->target->upper_half)
			b->price += b->target->pos;
		else
			b->price += len_a - b->target->pos;
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	best_price;
	t_stack	*cheapest;

	if (!b)
		return ;
	best_price = LONG_MAX;
	while (b)
	{
		if (b->price < best_price)
		{
			best_price = b->price;
			cheapest = b;
		}
		b = b->next;
	}
	cheapest->cheapest = 1;
	set_rest(b, cheapest);
}

void	set_params(t_stack *a, t_stack *b)
{
	current_pos(a);
	current_pos(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
