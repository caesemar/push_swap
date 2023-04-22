/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:04:36 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/22 05:46:10 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	ft_error_check(char **argv,	int *space)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((ft_isdigit(argv[i][j]) == 1) || argv[i][j] == ' ')
			{
				if (argv[i][j] == ' ')
					*space = 1;
				j++;
			}
			else
			{
				ft_putstr_fd("Error: not a digit or space on input\n", 2);
				exit(1);
			}
		}
		j = 0;
		i++;
	}
}
static int	ft_duplicate(char c, char **argv, int i, int j)
{
	j++;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == c && ft_isdigit(c) == 1)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
//buscar espacio, si hay spacio -> split, pasarle eso a ft_duplicate (hay que hacer tb split aqui de ese *argv y los siguientes) y hacer un strncmp si tienen el mismo len 
static void	ft_duplicate_check(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i])
	{	
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			else if (ft_duplicate(argv[i][j], argv, i, j) == 0)
				j++;
			else
			{
				ft_putstr_fd("Error: duplicate number found\n", 2);
				exit (1);
			}		
		}
		j = 0;
		i++;
	}
}

void	split_input(char **argv, t_stack **a, t_lst *new_node)
{
	int		i;
	char	**temp;
	int		j;

	j = -1;
	i = 0;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return ;
		while (temp[++j])
			*a = add_to_end(ft_atoi(temp[j]), *a);
		j = -1;
		ft_free2d(temp);
	}
}

void	ft_input_checker(char **argv, t_stack **a, t_lst *new_node)
{
	int	space;

	space = 0;
	ft_error_check(argv, &space);
	ft_duplicate_check(argv);
	split_input(argv, a, new_node);
}
