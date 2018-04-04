/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:06:20 by aledru            #+#    #+#             */
/*   Updated: 2018/04/04 20:06:24 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_SOLVER_H
# define SUDOKU_SOLVER_H

# include <unistd.h>

int		present_block(int digit, int line, int col, int grid[9][9]);
int		present_line(int digit, int line, int grid[9][9]);
int		present_col(int digit, int col, int grid[9][9]);
int		check_nb(char **grid);
int		check_col_line_group(int grid[9][9]);
int		check_norm(char **grid);
int		comp_tab(int s1[9][9], int s2[9][9]);
int		present_block_init(int line, int col, int grid[9][9]);
int		present_line_init(int line, int col, int grid[9][9]);
int		present_col_init(int line, int col, int grid[9][9]);

#endif
