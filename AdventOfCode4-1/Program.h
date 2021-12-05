#pragma once

#include <string>
#include <vector>

class Grid;

class Program
{
public:
	Program();
	~Program();

	void ProcessInput(std::vector<std::string>);
	void Solve();

private:
	std::vector<Grid*> m_grid;
	std::vector<int> m_numbers;
};

