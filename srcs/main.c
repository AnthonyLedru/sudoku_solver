/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:55:03 by aledru            #+#    #+#             */
/*   Updated: 2018/04/04 19:55:05 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_solver.h"

void	print(int grid[9][9])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		is_valid(int grid[9][9], int pos)
{
	int line;
	int col;
	int digit;

	if (pos == 81)
		return (1);
	digit = 1;
	line = pos / 9;
	col = pos % 9;
	if (grid[line][col] != 0)
		return (is_valid(grid, pos + 1));
	while (digit <= 9)
	{
		if (present_block(digit, line, col, grid) == 0
			&& present_line(digit, line, grid) == 0
			&& present_col(digit, col, grid) == 0)
		{
			grid[line][col] = digit;
			if (is_valid(grid, pos + 1) == 1)
				return (1);
		}
		digit++;
	}
	grid[line][col] = 0;
	return (0);
}

int		is_valid_inv(int grid[9][9], int pos)
{
	int line;
	int col;
	int digit;

	if (pos == 0)
		return (1);
	digit = 1;
	line = pos / 9;
	col = pos % 9;
	if (grid[line][col] != 0)
		return (is_valid_inv(grid, pos - 1));
	while (digit <= 9)
	{
		if (present_block(digit, line, col, grid) == 0
			&& present_line(digit, line, grid) == 0
			&& present_col(digit, col, grid) == 0)
		{
			grid[line][col] = digit;
			if (is_valid_inv(grid, pos - 1) == 1)
				return (1);
		}
		digit++;
	}
	grid[line][col] = 0;
	return (0);
}

void	copy_tab(char *argv[], int ptr[9][9], int ptr_inv[9][9])
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (argv[i][j] == '.')
			{
				ptr[i - 1][j] = 0;
				ptr_inv[i - 1][j] = 0;
			}
			else
			{
				ptr[i - 1][j] = argv[i][j] - 48;
				ptr_inv[i - 1][j] = argv[i][j] - 48;
			}
		}
	}
}

int		main(int argc, char *argv[])
{
	int		ptr[9][9];
	int		ptr_inv[9][9];

	if (argc != 10)
		write(1, "Error\n", 6);
	else if (check_nb(argv) == 0)
		write(1, "Error\n", 6);
	else if (check_norm(argv) == 0)
		write(1, "Error\n", 6);
	else
	{
		copy_tab(argv, ptr, ptr_inv);
		if (check_col_line_group(ptr) == 0)
			write(1, "Error\n", 6);
		else
		{
			is_valid(ptr, 0);
			is_valid_inv(ptr_inv, 80);
			if (comp_tab(ptr, ptr_inv) == 0)
				write(1, "Error\n", 6);
			else
				print(ptr);
		}
	}
	return (0);
}
