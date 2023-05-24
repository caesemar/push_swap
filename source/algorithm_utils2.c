/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:58:18 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/24 22:30:40 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	less_than_ten_elem(t_lst **a, t_lst **b)
{
	while (sorted(a) == 1)
	{
		while (stack_size(a) > 3)
			push_index(a, b, min_index(a));
		three_elem(a);
		while (stack_size(b) > 0)
			print_pa(a, b);
	}
}

int	get_index(t_lst **a, int num)
{
	t_lst	*temp;
	int		position;

	temp = *a;
	position = 0;
	while (temp != NULL)
	{
		if (temp->index == num)
			return (position);
		position++;
		temp = temp->next;
	}
	return (-1);
}

void	push_numb(t_lst **a, t_lst **b, int num)
{
	t_lst	*temp;
	int		position;
	int		half;

	half = stack_size(a) / 2;
	temp = *a;
	position = get_index(a, num);
	if (position == -1)
		return ;
	while (position != 0)
	{
		position = get_index(a, num);
		if (position <= half)
			print_ra(a);
		else
			print_rra(a);
	}
	print_pb(a, b);
}

void	push_index(t_lst **a, t_lst **b, int index)
{
	t_lst	*temp;
	int		half;
	int		new_index;

	half = stack_size(a) / 2;
	temp = *a;
	new_index = index;
	if (index == -1)
		return ;
	while (index != 0)
	{
		if (index < half)
		{
			print_ra(a);
			index--;
		}
		else
		{
			if (index >= stack_size(a))
				break ;
			print_rra(a);
			index++;
		}
	}
	print_pb(a, b);
}

void	sort_long_stack(t_lst **a)
{
	int		chunk;

	while (sorted (a) == 1)
	{

	}
}
