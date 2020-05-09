#include "hourlyemployee.hpp"

/*****************************************************************************/

HourlyEmployee::HourlyEmployee(std::string const & _name, double _paymentPerHour)
	:   Employee(_name),
		m_paymentPerHour(_paymentPerHour),
		m_workedHoursCounter(0)
{

}

void HourlyEmployee::doWork(double _hours)
{
	this->printWorking(std::cout, _hours);

	m_workedHoursCounter += _hours;
}

double HourlyEmployee::calculatePayment() const
{
	return ((m_paymentPerHour*m_workedHoursCounter) + this->getpremium());
}

/*****************************************************************************/
