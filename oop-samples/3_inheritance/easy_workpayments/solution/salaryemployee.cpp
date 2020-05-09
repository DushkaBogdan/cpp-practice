#include "salaryemployee.hpp"

/*****************************************************************************/

SalaryEmployee::SalaryEmployee(std::string const & _name, double _fixedSalary)
	:Employee(_name), m_fixedSalary(_fixedSalary)
{}

void SalaryEmployee::doWork(double _hours)
{
	this->printWorking(std::cout, _hours);
}

double SalaryEmployee::calculatePayment() const
{
	return (m_fixedSalary + this->getpremium());
}
/*****************************************************************************/
