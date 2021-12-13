#pragma once

#include <string>
#include <vector>

class Program
{
public:
	Program();
	~Program();

	void ProcessInput(std::string);
	void Solve();
	bool CheckAround(int row, int coll);

private:
	std::vector<std::vector<int>> m_grid;

};

