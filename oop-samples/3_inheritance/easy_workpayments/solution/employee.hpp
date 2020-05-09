#ifndef _EMPLOYEE_HPP_
#define _EMPLOYEE_HPP_

/*****************************************************************************/

#include <iostream>
#include <string>

class Employee
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	~Employee();

	virtual void doWork(double _hours) = 0;

	virtual double calculatePayment() const = 0;

	void addPremium(double _premium);

	const std::string getName() const;

	double getpremium() const;

	void printWorking(std::ostream &_o, double _hours);

/*-----------------------------------------------------------------*/

protected:

/*-----------------------------------------------------------------*/

	Employee(std::string const & _name);

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Employee(const Employee &);
	Employee & operator = (const Employee &);

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const std::string m_sName;
	double m_premiumSum;

};

inline void 
Employee::addPremium(double _premium)
{
	m_premiumSum += _premium;
}

inline const std::string
Employee::getName() const
{
	return m_sName;
}

inline double
Employee::getpremium() const
{
	return m_premiumSum;
}

/*****************************************************************************/

#endif // _EMPLOYEE_HPP_
