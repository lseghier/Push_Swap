/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:53:47 by lseghier          #+#    #+#             */
/*   Updated: 2023/12/17 01:38:15 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				price;
	int				upper_half;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/*                      Move functions                      */
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

/*                       Initializing                       */
void				fill_stack(t_stack **a, char **argv, int free_bool);

/*                       Utils functions                    */
t_stack				*ft_stacklast(t_stack *lst);
int					lenstack(t_stack *a);
int					sorted_stack(t_stack *a);
t_stack				*find_biggest(t_stack *a);
void				add_stack(t_stack **a, int n);
t_stack				*find_smallest(t_stack *a);
void				current_pos(t_stack *a);
t_stack				*find_cheapest(t_stack *b);
void				set_rest(t_stack *b, t_stack *cheapest);
char				**ft_split(char const *s, char c);

/*                       Sorting function                   */
void				set_params(t_stack *a, t_stack *b);
void				sort_stack(t_stack **a, t_stack **b);
void				tiny_sort(t_stack **a);

/*                       Free and error handling functions  */
void				free_stack(t_stack **a);
int					error_syntax(char *str);
int					error_repeated(t_stack *a, int n);
void				free_all(t_stack **a, char **argv, int free_bool);
void				free_matrix(char **argv);
void				ft_lstdelone(t_stack *lst);

#endif
