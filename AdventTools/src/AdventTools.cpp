#include "AdventTools.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace AdventTools
{
	std::vector<std::string> LoadInput()
	{
		std::fstream file;
		std::vector<std::string> lines;
		file.open("input.txt", std::ios::in);

		if (!file.is_open())
		{
			printf("Failed to open file <input.txt>");
			return lines;
		}

		std::string newLine;
		
		//Read file
		while (std::getline(file, newLine))
		{
			lines.push_back((newLine));
		}

		file.close();
		return lines;
	}
}