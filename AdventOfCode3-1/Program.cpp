#include "Program.h"

#include <iostream>
#include <fstream>
#include <vector>

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
	Solve(lines);

	file.close();
}

Program::~Program()
{
	
}

void Program::Solve(std::vector<std::string> lines)
{
	std::vector<int> ones = std::vector<int>(lines[0].length());
	uint32_t gamma = 0;
	uint32_t epsilon = 0;
	for (std::string str : lines)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '1')
				ones[i]++;
		}
	}
	
	for (int i = 0; i < ones.size(); i++)
	{
		if (ones[i] > lines.size() * 0.5f)
		{
			gamma |= 1UL << ones.size() - 1 - i;
		}
		else
		{
			epsilon |= 1UL << ones.size() - 1 - i;
		}
	}
	printf("result: %i\n", gamma * epsilon);
}