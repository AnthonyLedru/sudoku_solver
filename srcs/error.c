/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 11:55:57 by aledru            #+#    #+#             */
/*   Updated: 2017/07/16 17:10:35 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_solver.h"

int		check_nb(char **grid)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (grid[i])
	{
		while (grid[i][j])
			j++;
		i++;
		if (j != 9)
			return (0);
		j = 0;
	}
	return (1);
}

int		check_col_line_group(int grid[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (present_block_init(i, j, grid) == 1
				|| present_line_init(i, j, grid) == 1
				|| present_col_init(i, j, grid) == 1)
			{
				if (grid[i][j] != 0)
					return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int		check_norm(char **grid)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (grid[i][j] <= '0' || grid[i][j] > '9')
			{
				if (grid[i][j] != '.')
					return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
