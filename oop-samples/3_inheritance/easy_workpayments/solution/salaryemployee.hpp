#ifndef _SALARYEMPLOYEE_HPP_
#define _SALARYEMPLOYEE_HPP_

/*****************************************************************************/

#include "employee.hpp"

/*****************************************************************************/


class SalaryEmployee
	:	public Employee
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	SalaryEmployee(std::string const & _name, double _fixedSalary);

	void doWork(double _hours) override;

	double calculatePayment() const override;

	double getFixedSalary() const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	double m_fixedSalary;

};

inline double
SalaryEmployee::getFixedSalary() const
{
	return m_fixedSalary;
}


/*****************************************************************************/

#endif // _SALARYEMPLOYEE_HPP_
