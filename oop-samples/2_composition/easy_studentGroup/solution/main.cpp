#include "application.hpp"

#include <iostream>
#include "vld.h"

/*****************************************************************************/


int main ()
{
	try
	{
		Application theApp;
		
		theApp.generateTestModel();

		theApp.printBudgetStudentsCount();
		theApp.printContractStudentsCount();
		theApp.printStudentsBornFirstDayOfMonth();
		theApp.printEldestStudent();
	}
	catch ( const char * _s )
	{
		std::cerr << _s << std::endl;
		return -1;
	}

	return 0;
}


/*****************************************************************************/
