#include "MCTime.h"

#include<iostream>

void MCTime_test1() {
	using namespace MCTIME;
	MCTime start;
	for (int i = 1; i != 1000; ++i) {
		std::cout << i << " ";
		if (i % 10 == 0)
			std::cout << std::endl;
	}
	MCTime end;
	std::cout << std::endl;
	std::cout << "start = " << start.ascii();
	std::cout << "end = " << end.ascii();
	std::cout << "delta = " << end.delta(&start);
}