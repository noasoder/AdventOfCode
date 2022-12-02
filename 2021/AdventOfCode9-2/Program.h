#pragma once

#include <string>
#include <vector>

class Program
{
public:
	struct Basin {
		std::vector<int> nodes;
	};
	struct Coord {
		int x, y;
	};

	Program();
	~Program();

	void ProcessInput(std::string);
	void Solve();
	bool TryAddBasin(int row, int coll);

private:
	void SolveBasin(Basin& basin, int x, int y);
	int* GetNode(int x, int y);
	bool DoNode(std::vector<Coord>& vec, Coord n);
	void PrintGrid();
	int GetScoreFromLargest(int amount);
	int GetBasinScore(Program::Basin basin);

	std::vector<std::vector<int>> m_grid;
	std::vector<Basin> m_basins;
};

