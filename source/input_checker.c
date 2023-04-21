/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:04:36 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/21 04:17:50 by jocasado         ###   ########.fr       */
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
			if (argv[i][j] == c)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

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
			if (ft_duplicate(argv[i][j], argv, i, j) == 0)
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

void	**split_input(char **argv, t_stack *a)
{
	int		i;
	char	**temp;

	i = 0;
	while (argv[i])
	{
			temp = ft_split(argv[i], ' ');
			while (temp[j])
			{
				a->content = ft_atoi(temp[j][0]);
				
			}
			ft_free2d(temp);
	}
}

char	**ft_input_checker(char **argv, int	*num_elem, t_stack *a)
{
	int	space;

	space = 0;
	ft_error_check(argv, &space);
	ft_duplicate_check(argv);
	split_input(argv, a);
	while (argv[*num_elem])
	{		
		*num_elem = *num_elem + 1;
	}
	return (NULL);
}
