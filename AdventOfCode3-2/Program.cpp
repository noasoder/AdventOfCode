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

	std::vector<uint16_t> ints;
	std::vector<std::string> lines;
	std::string newLine;
	
	while (std::getline(file, newLine))
	{
		ints.push_back(BitsToInt(newLine));
		lines.push_back(newLine);
	}

	Solve(ints, lines[0].length());

	file.close();
}

Program::~Program()
{
	
}

std::vector<uint16_t> SortOut(std::vector<uint16_t> lines, int bits, bool removeLargest)
{
	std::vector<uint16_t> ones;
	std::vector<uint16_t> zeros;

	for (int i = 0; i < bits; i++)
	{
		for (uint16_t line : lines)
		{
			if ((line >> bits - 1 - i) & 1U)
				ones.push_back(line);
			else
				zeros.push_back(line);
		}

		if (removeLargest)
		{
			if (ones.size() >= zeros.size())
				lines = ones;
			else
				lines = zeros;
		}
		else
		{
			if (zeros.size() <= ones.size())
				lines = zeros;
			else
				lines = ones;
		}

		ones.clear();
		zeros.clear();

		if (lines.size() <= 1)
			return lines;
	}

	return lines;
}

void Program::Solve(std::vector<uint16_t> lines, int bits)
{
	std::vector<uint16_t> oxygen = lines;
	std::vector<uint16_t> co2 = lines;
	
	oxygen = SortOut(oxygen, bits, true);
	co2 = SortOut(co2, bits, false);

	printf("result: %i\n", oxygen[0] * co2[0]);
}