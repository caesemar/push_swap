/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:58:18 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/16 21:51:36 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	less_than_ten_elem(t_lst **a, t_lst **b)
{
	t_lst	*temp;

	while (sorted(a) == 1)
	{	
		while (stack_size(a) > 3)
			print_pb(a, b);
		three_elem(a);
		while (stack_size(b) > 0)
		{
			if (stack_size(b) < 3)
			{
				three_elem(b);
				while (stack_size(b) > 0)
					print_pa(a, b);
			}
			print_pa(a, b);
			temp = *a;
			if (temp->index > temp->next->index)
				print_ra(a);
		}
	}
}
