/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:56:50 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/27 04:03:48 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	find_chunk_elem(t_lst **a, int chunk_start, int chunk_limit)
{
	int	i;
	int	position;
	int	r_position;
	int	from_end;
	int	r_from_end;

	i = chunk_start;
	r_position = stack_size(a) + 1;
	from_end = stack_size(a) + 1;
	r_from_end = stack_size(a) + 1;
	while (i <= chunk_limit)
	{
		position = get_index(a, i);
		if (position >= 0)
		{
			from_end = stack_size(a) - position;
			if (position > -1 && (((r_position > position) && \
				(r_from_end > position)) || \
				((r_position > from_end) && (r_from_end > from_end))))
				r_position = position;
			r_from_end = stack_size(a) - r_position;
		}
		i++;
	}
	return (r_position);
}

void	push_index_b(t_lst **a, t_lst **b, int index)
{
	if (index == -1)
		return ;
	while (index != 0)
	{
		if (index <= stack_size(b) / 2)
		{
			if (index == 1)
				print_sb(b);
			else
				print_rb(b);
			index--;
		}
		else
		{
			if (index >= stack_size(b))
				break ;
			print_rrb(b);
			index++;
		}
	}
	print_pa(a, b);
}
