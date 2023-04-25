/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:08:56 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/25 02:37:53 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_free2d(char	**tofree)
{
	size_t	i;

	i = 0;
	while (tofree[i])
		free (tofree[i++]);
	free (tofree);
}

t_lst	*create_node(int content)
{
	t_lst	*node;

	node = (t_lst *) malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
t_lst	*push(t_lst *top_stack, t_lst *head)
{
	t_lst	*new_stack;

	new_stack = (t_lst *)malloc(sizeof(t_lst));
	if (new_stack == NULL)
		return (NULL);
	new_stack->first = head;
	new_stack->next = top_stack;
	return (new_stack);
}
*/
void	add_to_end(int value, t_lst **s)
{
	t_lst	*new_node;
	t_lst	*current_node;

	new_node = create_node(value);
	if (*s == NULL)
		*s = new_node;
	else
	{
		current_node = *s;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
}
