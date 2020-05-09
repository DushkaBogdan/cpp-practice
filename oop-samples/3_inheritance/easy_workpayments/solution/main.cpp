#include "controller.hpp"

#include <iostream>
#include <cassert>

/*****************************************************************************/


void runTest1 ()
{
	Controller controller;

	controller.createHourlyEmployee( "Ivanov", 15.00 );
	controller.createSalaryEmployee( "Petrov", 1000.00 );
	controller.createInternEmployee( "Sidorov", 20.0 );

	assert( controller.getTotalPayment() == 1000.0 ); // Petrov is being payed regardless of actual work done

	controller.trackWork( "Ivanov", 24.00 );
	controller.trackWork( "Petrov", 50.00 );
	
	assert( controller.getPayment( "Ivanov" ) == 24.00 * 15.00 );
	assert( controller.getPayment( "Petrov" ) == 1000.00 );

	controller.giveBonus( "Ivanov", 100.0 );
	assert( controller.getPayment( "Ivanov" ) == 24.00 * 15.00 + 100.0 );

	controller.trackWork( "Sidorov", 10.0 );
	controller.giveBonus( "Sidorov", 200.0 );
	assert( controller.getPayment( "Sidorov" ) == 200.0 );

	assert( controller.getTotalPayment() == 
				( controller.getPayment( "Ivanov" ) +
				  controller.getPayment( "Petrov" ) + 
				  controller.getPayment( "Sidorov" ) ) );
}


/*****************************************************************************/


int main ()
{
	try
	{
		runTest1();
	}
	catch ( const char * _s )
	{
		std::cerr << _s << std::endl;
		return -1;
	}

	return 0;
}


/*****************************************************************************/
