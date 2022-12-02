#include "Program.h"

#include <AdventTools.h>
#include <iostream>

int Solve(std::vector<int>& numbers)
{
	int biggest = 0;
	for (auto& num : numbers)
	{
		if (num > biggest)
		{
			biggest = num;
		}
	}
	return biggest;
}

Program::Program()
{
	auto lines = AdventTools::LoadInput();

	std::vector<int> numbers;
	numbers.push_back(0);

	for (auto& line : lines)
	{
		if (line == "")
		{
			numbers.push_back(0);
			continue;
		}

		numbers[numbers.size() - 1] += std::stoi(line);
	}

	printf("result is: %i\n", Solve(numbers));
}

Program::~Program()
{

}