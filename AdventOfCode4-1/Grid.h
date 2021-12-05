#pragma once

#include <vector>

#define GRID_SIZE 5

class Grid
{
public:
	Grid() {};
	Grid(std::vector<int> input) 
	{
		SetGrid(input);
	};
	~Grid() {};

	void SetGrid(std::vector<int>);
	int GetPoints(int);

	//returns the score if the board has a bingo
	int AddPoint(int);

private:

	int m_grid[GRID_SIZE][GRID_SIZE];
	bool hasWon = false;
};
