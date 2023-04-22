/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:08:56 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/22 03:47:47 by jocasado         ###   ########.fr       */
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

t_stack	*pop(t_stack *a)
{
	t_stack	*new_stack;

	if (a == NULL)
		return (NULL);
	new_stack = a->next;
	free(a);
	return (new_stack);
}

t_stack	*push(t_stack *top_stack, t_lst *head)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->first = head;
	new_stack->next = top_stack;
	return (new_stack);
}

t_stack	*add_to_end(int value, t_stack *s)
{
	t_lst	*new_node;
	t_stack	*new_stack;
	t_stack	*current_stack;

	new_node = create_node(value);
	new_stack = NULL;
	new_stack = push(new_stack, new_node);
	if (s == NULL)
		return (new_stack);
	current_stack = s;
	while (current_stack->next != NULL)
		current_stack = current_stack->next;
	current_stack->next = new_stack;
	return (s);
}
