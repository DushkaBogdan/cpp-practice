#include "internemployee.hpp"
/*****************************************************************************/

InternEmployee::InternEmployee(std::string const & _name, double _limitedHours)
	:Employee(_name), m_limitedHours(_limitedHours)
{}

void InternEmployee::doWork(double _hours)
{
	printWorking(std::cout, _hours);
}

double InternEmployee::calculatePayment() const
{
	return this->getpremium();
}

/*****************************************************************************/
