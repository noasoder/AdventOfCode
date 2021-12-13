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

	for (int lantern : m_lanterns)
	{
		m_days[lantern]++;
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
	for (int j = 0; j < line.size(); j++)
	{
		if (j + 1 == line.size())
		{
			m_lanterns.push_back(std::stoi(line.substr(j - (numberOfDigits), numberOfDigits + 1)));
			numberOfDigits = 0;
		}
		else
		{
			if (line[j] == ',')
			{
				if (numberOfDigits > 0)
				{
					m_lanterns.push_back(std::stoi(line.substr(j - numberOfDigits, numberOfDigits)));
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


void Program::Solve()
{
	for (int i = 0; i < DAYS; i++)
	{
		printf("Started day %i\n", i);
		DoOneDay();
	}
	std::cout << "final lanterns: " << GetLanternAmount() << std::endl;
}

void Program::DoOneDay()
{
	m_days[m_currentDay + 9] += m_days[m_currentDay];
	m_days[m_currentDay + 7] += m_days[m_currentDay];
	m_days[m_currentDay] = 0;
	m_currentDay++;
	std::cout << "current lanterns: " << GetLanternAmount() << std::endl;
}