#include <iostream>
#include "vld.h"
#include "Controller.hpp"

int main()
{

	try
	{
		Controller controller;

		controller.runTest();
		
	}
	catch (const char*_s)
	{
		std::cerr << _s << std::endl;
	}
}