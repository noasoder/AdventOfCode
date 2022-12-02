#pragma once

#include <string>
#include <vector>

#define DAYS 256

class Program
{
public:
	Program();
	~Program();

	void ProcessInput(std::string);
	void Solve();
	void DoOneDay();
	long long GetLanternAmount()
	{
		long long total = 0;
		for (long long day : m_days)
		{
			total += day;
		}
		return total;
	}

private:
	std::vector<int> m_lanterns;

	long long m_days[DAYS + 10];
	int m_currentDay = 0;
};

