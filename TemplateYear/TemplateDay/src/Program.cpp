#include "Program.h"

#include <iostream>
#include <AdventTools.h>

int Solve(std::vector<std::string> lines)
{
	return lines.size;
}

Program::Program()
{
	auto lines = AdventTools::LoadInput();

	printf("result is: %i\n", Solve(lines));
}

Program::~Program()
{

}