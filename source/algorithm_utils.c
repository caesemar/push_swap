/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:21:31 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/16 20:41:26 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	sorted(t_lst **a)
{
	t_lst	*temp;

	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->index < temp->next->index)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

int	stack_size(t_lst **a)
{
	int		i;
	t_lst	*temp;

	i = 0;
	temp = *a;
	while (temp != NULL)
	{
			i++;
			temp = temp->next;
	}
	return (i);
}
int	min_index(t_lst **a)
{
	t_lst	*temp;
	int		index;
	t_lst	*temp1;
	int		position;

	temp = *a;
	index = 0;
	position = 0;
	temp1 = temp->next;
	while (temp1 != NULL)
	{
		if (temp->index > temp1->index)
		{
			index = position + 1;
			temp = temp1;
		}
		temp1 = temp1->next;
		position++;
	}
	return (index);
}
int	max_index(t_lst **a)
{
	t_lst	*temp;
	int		index;
	t_lst	*temp1;
	int		position;

	temp = *a;
	index = 0;
	position = 0;
	temp1 = temp->next;
	while (temp1 != NULL)
	{
		if (temp->index < temp1->index)
		{
			index = position + 1;
			temp = temp1;
		}
		temp1 = temp1->next;
		position++;
	}
	return (index);
}

void	three_elem(t_lst **a)
{
	int		index_min;
	int		index_max;

	while (sorted(a) == 1)
	{
		index_min = min_index(a);
		index_max = max_index(a);
		if (index_min == 1 && index_max == 0)
			print_ra(a);
		else if (index_min == 2 && index_max == 1)
			print_rra(a);
		else
			print_sa(a);
	}
}
