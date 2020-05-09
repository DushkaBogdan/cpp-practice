#ifndef _INTERNEMPLOYEE_HPP_
#define _INTERNEMPLOYEE_HPP_

/*****************************************************************************/

#include "employee.hpp"

/*****************************************************************************/


class InternEmployee
	:	public Employee
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	InternEmployee(std::string const &_name, double _limitedHours);

	void doWork(double _hours) override;

	double calculatePayment() const override;

	double getLimitedHours() const { return m_limitedHours; };

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	double m_limitedHours;
};


/*****************************************************************************/

#endif // _INTERNEMPLOYEE_HPP_
