#include "Program.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>


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
	for (int i = 0; i < m_grid.size(); i++)
	{
		for (int j = 0; j < m_grid[i].size(); j++)
		{
			if (TryAddBasin(i, j))
			{
				//PrintGrid();
				//printf("\n");
			}
		}
	}

	//PrintGrid();

	int score = GetScoreFromLargest(3);

	std::cout << "final result: " << score << std::endl;
}

bool Program::TryAddBasin(int row, int coll)
{
	int* current = &m_grid[row][coll];

	if (*current == -1 || *current >= 9)
		return false;

	//create basin
	Basin basin{};
	SolveBasin(basin, row, coll);
	m_basins.push_back(basin);

	*current = -1;
	return true;
}

int* Program::GetNode(int x, int y)
{
	return &m_grid[x][y];
}

bool Program::DoNode(std::vector<Coord>& vec, Coord pos)
{
	int* curr = &m_grid[pos.x][pos.y];

	if (*curr < 9 && *curr > -1)
	{
		vec.push_back(pos);
		return true;
	}

	return false;
}

void Program::SolveBasin(Basin& basin, int x, int y) 
{
	std::vector<Coord> openList;

	openList.push_back(Coord{x, y});

	while (!openList.empty())
	{
		Coord pos = openList[openList.size() - 1];


		int* curr = &m_grid[pos.x][pos.y];
		if (*curr >= 0)
		{
			basin.nodes.push_back(*curr);
			*curr = -1;
			openList.pop_back();

			if (pos.x - 1 >= 0 && pos.x - 1 < 100)
			{
				DoNode(openList, Coord{ pos.x - 1, pos.y });
			}
			if (pos.x + 1 >= 0 && pos.x + 1 < 100)
			{
				DoNode(openList, Coord{ pos.x + 1, pos.y });
			}
			if (pos.y - 1 >= 0 && pos.y - 1 < 100)
			{
				DoNode(openList, Coord{ pos.x, pos.y - 1 });
			}
			if (pos.y + 1 >= 0 && pos.y + 1 < 100)
			{
				DoNode(openList, Coord{ pos.x, pos.y + 1 });
			}
		}
		else
		{
			openList.pop_back();
		}
	}
}

int Program::GetScoreFromLargest(int amount)
{
	std::vector<Basin> highest;
	int maxHigh = INT_MAX;

	for (int i = 0; i < amount; i++)
	{
		int highestScore = 0;
		Basin highestBasin{};
		for (Basin basin : m_basins)
		{
			int score = GetBasinScore(basin);
			if (score > highestScore && score < maxHigh)
			{
				highestBasin = basin;
				highestScore = score;
			}
		}
		maxHigh = highestScore;
		highest.push_back(highestBasin);
	}

	int score = 1;
	for (Basin basin : highest)
	{
		score *= basin.nodes.size();
	}

	return score;
}

int Program::GetBasinScore(Program::Basin basin)
{
	return basin.nodes.size();
}

void Program::PrintGrid()
{
	for (std::vector<int> row : m_grid)
	{
		for (int i : row)
		{
			if(i < 0)
				printf("-");
			else
				printf("%i", i);
		}
		printf("\n");
	}
}