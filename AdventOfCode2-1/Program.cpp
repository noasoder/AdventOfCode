#include "Program.h"

#include <iostream>
#include <fstream>
#include <vector>

Program::Program()
{
	pos = Pos();
	pos.x = 0;
	pos.y = 0;

	std::fstream file;
	file.open("input.txt", std::ios::in);

	if (!file.is_open())
		return;

	//Read file
	std::string newLine;
	while (std::getline(file, newLine))
	{
		DecodeMessage(newLine);
	}

	file.close();

	printf("the result is: x = %i, y = %i (%i) \n", pos.x, pos.y, pos.x * pos.y);
}

Program::~Program()
{
	
}

void Program::DecodeMessage(std::string message)
{
	if (message.find("up") != std::string::npos)
	{
		Move(DIR::Up, message[(int)DIR::Up] - '0');
	}
	else if (message.find("down") != std::string::npos)
	{
		Move(DIR::Down, message[(int)DIR::Down] - '0');
	}
	else if (message.find("forward") != std::string::npos)
	{
		Move(DIR::Forward, message[(int)DIR::Forward] - '0');
	}
}

void Program::Move(DIR dir, int len)
{
	switch (dir)
	{
	case Program::Up:
		printf("up %i\n", len);
		pos.y -= len;
		break;

	case Program::Down:
		printf("down %i\n", len);
		pos.y += len;
		break;

	case Program::Forward:
		printf("forward %i\n", len);
		pos.x += len;
		break;

	default:
		break;
	}
}