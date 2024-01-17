/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 04:07:21 by lseghier          #+#    #+#             */
/*   Updated: 2023/12/17 01:54:49 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		free_bool;

	free_bool = 0;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		free_bool = 1;
	}
	fill_stack(&a, argv + 1, free_bool);
	if (!sorted_stack(a))
	{
		if (lenstack(a) == 2)
			ra(&a);
		else if (lenstack(a) == 3)
			tiny_sort(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
}
