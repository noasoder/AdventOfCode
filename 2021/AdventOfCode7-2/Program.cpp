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
	}

	ProcessInput(lines[0]);

	Solve();

	file.close();
}

Program::~Program()
{

}

void Program::ProcessInput(std::string line)
{
	int numberOfDigits = 0;
	for (int j = 0; j < line.size(); j++)
	{
		if (j + 1 == line.size())
		{
			m_numbers.push_back(std::stoi(line.substr(j - (numberOfDigits), numberOfDigits + 1)));
			numberOfDigits = 0;
		}
		else
		{
			if (line[j] == ',')
			{
				if (numberOfDigits > 0)
				{
					m_numbers.push_back(std::stoi(line.substr(j - numberOfDigits, numberOfDigits)));
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

int Program::MoveCrabs(int to)
{
	int result = 0;

	for (int num : m_numbers)
	{
		result += abs(num - to);

		for (int i = 0; i < abs(num - to); i++)
		{
			result += i;
		}
	}

	return result;
}

void Program::Solve()
{
	int sum = 0;
	for (int num : m_numbers)
	{
		sum += num;
	}
	sum /= m_numbers.size();

	int bestResult = INT_MAX;
	int optimalTo = 0;
	for (int i = 0; i < m_numbers.size(); i++)
	{
		int result = MoveCrabs(i);
		if (result < bestResult)
		{
			bestResult = result;
			optimalTo = i;
		}
	}

	printf("fuel used: %i, everybody went to: %i\n", bestResult, optimalTo);
}