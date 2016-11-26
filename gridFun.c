#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "definitions.h"

/*

gcc gridFun.c functions.c -o x

*/

int main()
{
	int** grid = NULL;
	int x = 3, y = 3, value = 1;

	setupGrid(&grid, x, y);
	initializeGrid(grid, x, y, value);	
	populateGrid(grid, x, y);

	printf("3 x 3 Grid Setup\n\n");
	printGrid(grid, x, y);

	printf("\nx axis flip\n\n");	
	xAxisFlip(grid, x, y);
	printGrid(grid, x, y);

	populateGrid(grid, x, y);
	printf("\ny axis flip\n\n");
	yAxisFlip(grid, x, y);
	printGrid(grid, x, y);

	populateGrid(grid, x, y);
	printf("\nrotate 90 degrees\n\n");
	rotate90(grid, x, y);
	printGrid(grid, x, y);

	populateGrid(grid, x, y);
	printf("\nrotate 180 degrees\n\n");
	rotate180(grid, x, y);
	printGrid(grid, x, y);

	populateGrid(grid, x, y);
	printf("\nrotate 270 degrees\n\n");
	rotate270(grid, x, y);
	printGrid(grid, x, y);

	freeGrid(grid, y);
}