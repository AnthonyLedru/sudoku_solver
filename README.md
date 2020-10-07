# Sudoku Solver
Solve a sudoku with backtracking method.

This code complies with the 42 school norm: https://github.com/AnthonyLedru/sudoku_solver/blob/master/norm.pdf

## Compiling
Run `make` command and an executable called `sudoku_solver` should be created.

## Usage
```
./sudoku_solver line0 line1 line2 line3 line4 line5 line6 line7 line8

Example of line "9...7...."

```

The grid you specifie must be valid or the program will print an error.

A valid grid has:
- Line well formated.
- Only one solution.

## Example

```
./sudoku_solver "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."

9 1 4 3 7 5 2 6 8
2 8 7 4 9 6 1 5 3
3 6 5 8 1 2 4 7 9
8 4 6 5 2 1 3 9 7
5 2 9 6 3 7 8 1 4
7 3 1 9 8 4 5 2 6
1 5 3 7 4 9 6 8 2
6 9 8 2 5 3 7 4 1
4 7 2 1 6 8 9 3 5
```
## Subject

https://github.com/AnthonyLedru/sudoku_solver/blob/master/colle01.pdf
