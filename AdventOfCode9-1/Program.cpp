#include "Program.h"

#include <iostream>
#include <fstream>
#include <vector>


uint16_t BitsToInt(std::string str)
{
	uint16_t result = 0;
	for (char c : str)
	{
		result = (result << 1) | (c - '0');
	}
	return result;
}



Program::Program()
{
	std::fstream file;
	file.open("input.txt", std::ios::in);

	if (!file.is_open())
		return;

	std::vector<std::string> lines;
	std::string newLine;

	while (std::getline(file, newLine))
	{
		lines.push_back(newLine);
		ProcessInput(newLine);
	}


	Solve();

	file.close();
}

Program::~Program()
{

}

void Program::ProcessInput(std::string line)
{
	int numberOfDigits = 0;
	std::vector<int> row;
	for (int j = 0; j < line.size(); j++)
	{
		row.push_back(std::stoi(line.substr(j, 1)));
	}
	m_grid.push_back(row);
}


void Program::Solve()
{
	int risk = 0;
	for (int i = 0; i < m_grid.size(); i++)
	{
		for (int j = 0; j < m_grid[i].size(); j++)
		{
			if (CheckAround(i, j))
			{
				risk += 1 + m_grid[i][j];
			}
		}
	}

	std::cout << "final result: " << risk << std::endl;
}

bool Program::CheckAround(int row, int coll)
{
	int current = m_grid[row][coll];

	int up = -1;
	int down = -1;
	int left = -1;
	int right = -1;

	if (row - 1 >= 0 && row - 1 < 100)
		up = m_grid[row - 1][coll];
	if (row + 1 >= 0 && row + 1 < 100)
		down = m_grid[row + 1][coll];
	if (coll - 1 >= 0 && coll - 1 < 100)
		left = m_grid[row][coll - 1];
	if(coll + 1 >= 0 && coll + 1 < 100)
		right = m_grid[row][coll + 1];

	if (up != -1)
	{
		if (current >= up)
			return false;
	}

	if (down != -1)
	{
		if (current >= down)
			return false;
	}

	if (left != -1)
	{
		if (current >= left)
			return false;
	}

	if (right != -1)
	{
		if (current >= right)
			return false;
	}

	return true;
}