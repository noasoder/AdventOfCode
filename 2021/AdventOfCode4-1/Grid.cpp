#include "Grid.h"

void Grid::SetGrid(std::vector<int> input)
{
	for (size_t i = 0; i < GRID_SIZE * GRID_SIZE; i++)
	{
		m_grid[i / 5][i % 5] = input[i];
	}
}

//Check if all are -1
bool CheckRow(std::vector<int> numbers)
{
	for (int n : numbers)
	{
		if (n != -1)
			return false;
	}
	return true;
}

int Grid::GetPoints(int multiplier)
{
	int* currentNode = 0;
	int sumOfUnmarked = 0;
	for (size_t i = 0; i < GRID_SIZE * GRID_SIZE; i++)
	{
		currentNode = &m_grid[i / 5][i % 5];
		if (*currentNode != -1)
		{
			sumOfUnmarked += *currentNode;
		}
	}
	return sumOfUnmarked * multiplier;
}

int Grid::AddPoint(int toAdd)
{
	if (hasWon)
		return 0;
	int* currentNode = 0;
	for (size_t i = 0; i < GRID_SIZE * GRID_SIZE; i++)
	{
		currentNode = &m_grid[i / 5][i % 5];
		if (*currentNode == toAdd)
		{
			*currentNode = -1;
			std::vector<int> horizontal{ m_grid[i / 5][0], m_grid[i / 5][1], m_grid[i / 5][2], m_grid[i / 5][3], m_grid[i / 5][4] };
			std::vector<int> vertical{ m_grid[0][i % 5], m_grid[1][i % 5], m_grid[2][i % 5], m_grid[3][i % 5], m_grid[4][i % 5] };
			if (CheckRow(horizontal))
			{
				hasWon = true;
				return GetPoints(toAdd);
			}
			if (CheckRow(vertical))
			{
				hasWon = true;
				return GetPoints(toAdd);
			}
		}
	}
	return 0;
}
