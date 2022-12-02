#include "Program.h"
#include <iostream>
#include <chrono>

int main()
{
	using std::chrono::high_resolution_clock;
	using std::chrono::duration;

	auto t1 = high_resolution_clock::now();
	Program* p = new Program();
	auto t2 = high_resolution_clock::now();

	duration<double, std::milli> ms_double = t2 - t1;
	std::cout << "computations took: " << ms_double.count() << " ms" << std::endl;
	delete p;
}