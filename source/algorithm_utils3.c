/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:56:50 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/26 01:36:45 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	find_chunk_elem(t_lst **a, int chunk_start, int chunk_limit)
{
	int	i;
	int	position;
	int	r_position;
	int	stack_size_;

	i = chunk_start;
	r_position = stack_size(a) + 1;
	stack_size_ = stack_size(a);
	while (i <= chunk_limit)
	{
		position = get_index(a, i);
		printf("position: %i\n",position);
		if (r_position > position
			|| (stack_size(a) - r_position) > (stack_size(a) - position))
			r_position = position;
		i++;
	}
	printf("r_position: %i\n",r_position);
	return (r_position);
}

void	push_index_b(t_lst **a, t_lst **b, int index)
{
	t_lst	*temp;
	int		half;

	half = stack_size(a) / 2;
	temp = *a;
	if (index == -1)
		return ;
	while (index != 0)
	{
		if (index < half)
		{
			print_rb(b);
			index--;
		}
		else
		{
			if (index >= stack_size(a))
				break ;
			print_rrb(b);
			index++;
		}
	}
	print_pa(a, b);
}
