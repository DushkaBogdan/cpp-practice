#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

/*****************************************************************************/

#include <string>

#include <vector>
#include <unordered_map>

//#include "messages.hpp"

/*****************************************************************************/
class Employee;

class Controller
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Controller ();

	~ Controller ();

	void createHourlyEmployee ( std::string const & _name, double _hourlyRate );

	void createSalaryEmployee ( std::string const & _name, double _monthPayment );

	void createInternEmployee ( std::string const & _name, double _workHoursLimit );

	void trackWork ( std::string const & _employeeName, double _hours );

	void giveBonus ( std::string const & _employeeName, double _bonusPayment );

	double getPayment ( std::string const & _employeeName ) const;

	double getTotalPayment () const;

	int getEmployeesNumber() const { return m_employees.size(); };

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Controller ( const Controller & );
	Controller & operator = ( const Controller & );

/*-----------------------------------------------------------------*/

	void nameCheker(std::string const & _name);
	void addNameToFamily(std::string const & _name);
	int getEmployeesPosition(std::string const & _name) const;

/*-----------------------------------------------------------------*/

	std::unordered_map<std::string, int>m_setByNames;

	std::vector<Employee*>m_employees;
	

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif //  _CONTROLLER_HPP_
