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
	int MoveCrabs(int to);

private:
	std::vector<int> m_numbers;
};

