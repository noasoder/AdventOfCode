#include "Program.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int Solve(std::vector<int>& numbers)
{
	int increases = 0;
	for (int i = 3; i < numbers.size(); i++)
	{
		int lastThree = numbers[i - 1] + numbers[i - 2] + numbers[i - 3];
		int currentThree = numbers[i - 0] + numbers[i - 1] + numbers[i - 2];

		printf("%i ", currentThree);
		if (currentThree > lastThree)
		{
			printf(" Increased\n");
			increases++;
		}
		else
		{
			printf(" Decreased\n");
		}
	}
	return increases;
}

Program::Program()
{
	std::fstream file;
	file.open("input.txt", std::ios::in);

	if (!file.is_open())
		return;

	std::vector<int> numbers;

	//Read file
	std::string newLine;
	while (std::getline(file, newLine))
	{
		numbers.push_back(std::stoi(newLine));
	}

	file.close();

	printf("result is: %i\n", Solve(numbers));
}

Program::~Program()
{

}