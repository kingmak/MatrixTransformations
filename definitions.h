#pragma once

void printGrid(int** grid, int x, int y);
void setupGrid(int*** grid, int x, int y);
void initializeGrid(int **grid, int x, int y, int value);
void freeGrid(int **grid, int y);

void populateGrid(int **grid, int x, int y);
void swap(int** grid, int a1, int b1, int a2, int b2);

// transformations
void xAxisFlip(int **grid, int x, int y); 
void yAxisFlip(int **grid, int x, int y); 
void rotate270(int **grid, int x, int y);
void rotate180(int **grid, int x, int y);
void rotate90(int **grid, int x, int y);