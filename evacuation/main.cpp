#include "stdafx.h"
#include <functional>

void runner(std::function<void()> func)
{
	func();
}

int main()
{
	// std::cout << "Tests Change" << std::endl;
	concurrency::basics::launching_threads();

}