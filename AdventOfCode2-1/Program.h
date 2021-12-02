#pragma once

#include <string>

class Program
{
public:
	struct Pos
	{
		int x, y;
	};
	enum DIR
	{
		Up = 3,
		Down = 5, 
		Forward = 8,
	};

	Program();
	~Program();

	void DecodeMessage(std::string message);
	void Move(DIR, int);

private:

	Pos pos;
};

