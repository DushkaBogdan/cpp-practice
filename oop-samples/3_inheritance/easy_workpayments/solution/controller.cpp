#include "messages.hpp"

#include "controller.hpp"

#include <cassert>
#include <typeinfo>

#include "hourlyemployee.hpp"
#include "salaryemployee.hpp"
#include "internemployee.hpp"
/*****************************************************************************/


Controller::Controller ()
{}


/*****************************************************************************/


Controller::~Controller ()
{
	for (int i = 0; i < getEmployeesNumber(); i++)
		delete m_employees[i];
}


/*****************************************************************************/


void 
Controller::createHourlyEmployee ( std::string const & _name, double _hourlyRate )
{
	// Possible problems:
	//  - name must be unique ( Messages::NonUniqueName )
	//  - hourly rate must be positive ( Messages::NonPositivePayment )

	
	this->nameCheker(_name);
	
	if (_hourlyRate <= 0)
		throw Messages::NonPositivePayment;
		
	addNameToFamily(_name);

	m_employees.push_back(new HourlyEmployee(_name, _hourlyRate));
}


/*****************************************************************************/


void
Controller::createSalaryEmployee ( std::string const & _name, double _monthPayment )
{
	// Possible problems:
	//  - name must be unique ( Messages::NonUniqueName )
	//  - hourly rate must be positive ( Messages::NonPositivePayment )

	this->nameCheker(_name);

	if (_monthPayment <= 0)
		throw Messages::NonPositivePayment;
		

	addNameToFamily(_name);

	m_employees.push_back(new SalaryEmployee(_name, _monthPayment));
}


/*****************************************************************************/


void 
Controller::createInternEmployee ( std::string const & _name, double _workHoursLimit )
{
	// Possible problems:
	//  - name must be unique ( Messages::NonUniqueName )
	//  - working hours limit must be positive ( Messages::NonPositiveHoursLimit )

	this->nameCheker(_name);

	if (_workHoursLimit <= 0)
		throw Messages::NonPositiveHoursLimit;
		
	addNameToFamily(_name);

	m_employees.push_back(new InternEmployee(_name, _workHoursLimit));
}


/*****************************************************************************/


void
Controller::trackWork(std::string const & _employeeName, double _hours)
{
	// Possible problems:
	//  - employee name is unknown ( Messages::UnknownEmployeeName )
	//  - amount of hours is negative ( Messages::NegativeWorkHours )
	//  - intern employee was overloaded ( Messages::OverloadedIntern )

	if (_hours < 0)
		throw Messages::NegativeWorkHours;

	int position = getEmployeesPosition(_employeeName);

	if (InternEmployee *pIntern = dynamic_cast<InternEmployee *> (m_employees[position]))
		if (pIntern->getLimitedHours() < _hours)
			throw Messages::OverloadedIntern;

	m_employees[position]->doWork(_hours);
}


/*****************************************************************************/


void
Controller::giveBonus ( std::string const & _employeeName, double _bonusPayment )
{
	// Possible problems:
	//  - employee name is unknown ( Messages::UnknownEmployeeName )
	//  - bonus amount is not positive ( Messages::NonPositivePayment )

	if (_bonusPayment < 0)
		throw Messages::NonPositivePayment;
		
	int position = getEmployeesPosition(_employeeName);

	m_employees[position]->addPremium(_bonusPayment);
}


/*****************************************************************************/


double 
Controller::getPayment ( std::string const & _employeeName ) const
{
	// Possible problems:
	//  - employee name is unknown ( Messages::UnknownEmployeeName )

	int position = getEmployeesPosition(_employeeName);

	return m_employees[position]->calculatePayment();
}


/*****************************************************************************/


double 
Controller::getTotalPayment () const
{
	double totalPayment = 0.0;

	int emplCount = getEmployeesNumber();
	for (int i = 0; i < emplCount; i++)
		totalPayment += m_employees[i]->calculatePayment();

	return totalPayment;
}


/*****************************************************************************/

void Controller::nameCheker(std::string const & _name)
{
	if (_name.empty())
		throw Messages::EmptyName;
		
	if (m_setByNames.count(_name))
		throw Messages::NonUniqueName;
}

void Controller::addNameToFamily(std::string const & _name)
{
	m_setByNames[_name] = getEmployeesNumber();
}

int Controller::getEmployeesPosition(std::string const & _name) const
{
	auto it = m_setByNames.find(_name);

	if (it == m_setByNames.end())
		throw Messages::UnknownEmployeeName;
		
	return it->second;
}