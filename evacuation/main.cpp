#include "stdafx.h"
#include <functional>

void runner(std::function<void()> func)
{
	func();
}

int main()
{
	concurrency::basics::launching_threads();

}