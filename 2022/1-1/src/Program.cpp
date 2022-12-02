#include "Program.h"

#include <AdventTools.h>
#include <iostream>
#include <algorithm>

int Solve(std::vector<int>& numbers)
{
	std::sort(numbers.begin(), numbers.end(), [](int i, int j) -> int { return i > j; });

	return numbers[0] + numbers[1] + numbers[2];
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