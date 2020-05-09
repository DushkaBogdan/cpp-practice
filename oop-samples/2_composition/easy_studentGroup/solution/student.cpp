#include "student.hpp"
#include "date.hpp"

/*****************************************************************************/

Student::Student(
	  int _id
	, const std::string &_name
	, Date &_date
	, Studying_Form _form
	)
	:m_id(_id), m_sName(_name), m_Date(_date), m_StudyingForm(_form)
{
	if (m_sName.empty())
		throw "Name can't be Empty!";

	if (m_Date >= Date())
		throw "Invalid date parameters";
}


/*****************************************************************************/
