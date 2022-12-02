#include "Program.h"
#include <Windows.h>
#include <cstdio>

int main()
{
	Program* p = new Program();
	delete p;

	bool isRunning = true;
	while (isRunning) if (GetKeyState(VK_ESCAPE) & 0x8000) isRunning = false;
}