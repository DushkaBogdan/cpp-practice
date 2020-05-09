#ifndef _HOURLYEMPLOYEE_HPP_
#define _HOURLYEMPLOYEE_HPP_

/*****************************************************************************/

#include "employee.hpp"

/*****************************************************************************/


class HourlyEmployee
	:	public Employee
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	HourlyEmployee(std::string const & _name, double _paymentPerHour);

	void doWork(double _hours) override;

	double calculatePayment() const override;

	double getPayPerHour() const;
	double getWorkedHours() const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	double m_paymentPerHour;
	double m_workedHoursCounter;

};

inline double
HourlyEmployee::getPayPerHour() const { return m_paymentPerHour; };

inline double
HourlyEmployee::getWorkedHours() const { return m_workedHoursCounter; };
/*****************************************************************************/

#endif // _HOURLYEMPLOYEE_HPP_
