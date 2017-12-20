#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

void initializeGrid(int **grid, int x, int y, int value)
{
	int i, j;

	for (i = 0; i < y; i++)
		for (j = 0; j < x; j++)
			grid[i][j] = value;
}

void setupGrid(int*** grid, int x, int y)
{
	int i, j;

	*grid = (int**) malloc (y * sizeof(int *));

	for (i = 0; i < y; i++)
		(*grid)[i] = (int *) malloc (x * sizeof(int));
}

void printGrid(int **grid, int x, int y)
{
	int i, j;

	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			printf("%d ", grid[i][j]);
		}

		printf("\n");
	}
}

void freeGrid(int **grid, int y)
{
	int i;

	for (i = 0; i < y; i++)
		free(grid[i]);
	free(grid);
}

void populateGrid(int **grid, int x, int y)
{
	int i, j;
	int count = 1;

	for (i = 0; i < y; i++)
	{

		for (j = 0; j < x; j++)
		{
			grid[i][j] = count;
			count++;
		}
	}
}

void swap(int** grid, int x1, int y1, int x2, int y2)
{
	int temp = grid[x1][y1];
	grid[x1][y1] = grid[x2][y2];
	grid[x2][y2] = temp;
}

void yAxisFlip(int **grid, int x, int y)
{
	int i, j;

	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x / 2; j++) // since we swap
		{
			swap(grid, i, j, i, x - j - 1); 
		}
	}
}

void xAxisFlip(int **grid, int x, int y)
{
	int i, j;

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y / 2; j++) // since we swap
		{
			swap(grid, j, i, y - j - 1, i); 
		}
	}
}

void rotate270(int **grid, int x, int y)
{
	rotate180(grid, x, y);
	rotate90(grid, x, y);
}

void rotate180(int **grid, int x, int y)
{
	xAxisFlip(grid, x, y);
	yAxisFlip(grid, x, y);
}

void rotate90(int **grid, int x, int y)
{
	/*

	1   2   3   4     90rotate =     13   9   5   1
	5   6   7   8                    14   10  6   2
	9   10  11  12                   15   11  7   3
	13  14  15  16                   16   12  8   4

	so basically each x row = length - y column
	example row 0 = (4 - 1) - 0 column
	example row 1 = (4 - 1) - 1 column

	but there is a better way, let's see there indexes:

	0, 0 | 0, 1 | 0, 2 | 0, 3    =   3, 0 | 2, 0 | 1, 0 | 0, 0
	1, 0 | 1, 1 | 1, 2 | 1, 3    =   3, 1 | 2, 1 | 1, 1 | 0, 1
	2, 0 | 2, 1 | 2, 2 | 2, 3    =   3, 2 | 2, 2 | 1, 2 | 0, 2
 	3, 0 | 3, 1 | 3, 2 | 3, 3    =   3, 3 | 2, 3 | 1, 3 | 0, 3

 	now we can just make a new grid and do the above assigment operation
 	and we are done.
 	*/

 	int **newGrid = NULL;
 	int i, j;

 	setupGrid(&newGrid, x, y);
	//initializeGrid(newGrid, x, y, 9);

	for (i = 0; i < y; i++)
		for (j = 0; j < x; j++)
			newGrid[i][j] = grid[x - 1 - j][i];

	for (i = 0; i < y; i++)
		memcpy(grid[i], newGrid[i], x * sizeof(int)); // since we will free newGrid

	freeGrid(newGrid, y);
}
