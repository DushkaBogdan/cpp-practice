#include "employee.hpp"

/*****************************************************************************/

Employee::Employee(std::string const & _name)
	:m_sName(_name), m_premiumSum(0)
{
}

Employee::~Employee()
{}

void Employee::printWorking(std::ostream &_o, double _hours)
{
	_o 	<< "Hourly Employee " << m_sName
		<< " is working for "
		<< _hours << " hours!"
		<< std::endl;
}
/*****************************************************************************/
