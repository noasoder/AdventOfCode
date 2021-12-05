#include "Program.h"

#include "Grid.h"

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
	}

	ProcessInput(lines);

	Solve();

	file.close();
}

Program::~Program()
{

}

void Program::ProcessInput(std::vector<std::string> lines)
{
	//convert first line
	int numberOfDigits = 0;
	for (int j = 0; j < lines[0].size(); j++)
	{
		if (j + 1 == lines[0].size())
		{
			m_numbers.push_back(std::stoi(lines[0].substr(j - (numberOfDigits), numberOfDigits + 1)));
			numberOfDigits = 0;
		}
		else
		{
			if (lines[0][j] == ',')
			{
				if (numberOfDigits > 0)
				{
					m_numbers.push_back(std::stoi(lines[0].substr(j - numberOfDigits, numberOfDigits)));
					numberOfDigits = 0;
				}
			}
			else
			{
				numberOfDigits++;
			}
		}
	}

	bool lastWasSpace = false;
	std::vector<int> gridValues;
	//find and create the boards
	for (int i = 1; i < lines.size(); i++)
	{
		if (lines[i] == "")
		{
			lastWasSpace = true;

			//Add the grid
			if (gridValues.size() > 0)
			{
				m_grid.push_back(new Grid(gridValues));
				gridValues.clear();
			}
		}
		else
		{
			lastWasSpace = false;
			int numberOfDigits = 0;
			for (int j = 0; j < lines[i].size(); j++)
			{
				if (j + 1 == lines[i].size())
				{
					gridValues.push_back(std::stoi(lines[i].substr(j - (numberOfDigits), numberOfDigits + 1)));
					numberOfDigits = 0;
				}
				else
				{
					if (lines[i][j] == ' ')
					{
						if (numberOfDigits > 0)
						{
							gridValues.push_back(std::stoi(lines[i].substr(j - numberOfDigits, numberOfDigits)));
							numberOfDigits = 0;
						}
					}
					else
					{
						numberOfDigits++;
					}
				}
			}
		}
	}
}

void Program::Solve()
{
	for (int num : m_numbers)
	{
		for (int i = 0; i < m_grid.size(); i++)
		{
			int score = m_grid[i]->AddPoint(num);
			if (score > 0)
			{
				printf("after drawing number [%i] grid [%i] won with a score of %i\n", num, i, score);
			}
		}
	}
}