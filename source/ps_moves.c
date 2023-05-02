/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:39:46 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/02 17:54:54 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(t_lst **a)
{
	t_lst	*head;
	t_lst	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = *a;
	temp = (*a)->next;
	head->next = temp->next;
	*a = temp;
	temp->next = head;
}

void	reverse_rotate(t_lst **a)
{
	t_lst	*head;
	t_lst	*tail;
	t_lst	*new_tail;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = *a;
	while ((*a)->next->next != NULL)
		*a = (*a)->next;
	new_tail = *a;
	*a = (*a)->next;
	new_tail->next = NULL;
	tail = *a;
	tail->next = head;
	*a = tail;
}

void	rotate(t_lst **a)
{
	t_lst	*head;
	t_lst	*tail;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = *a;
	while ((*a)->next != NULL)
		*a = (*a)->next;
	tail = *a;
	*a = head->next;
	tail->next = head;
	head->next = NULL;
}

void	push(t_lst **a, t_lst **b)
{
	t_lst	*temp_a;
	t_lst	*temp_b;

	if (*a == NULL)
		return ;
	temp_b = *b;
	temp_a = *a;
	*a = (*a)->next;
	*b = temp_a;
	(*b)->next = temp_b;
}
