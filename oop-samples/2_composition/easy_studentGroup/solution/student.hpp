#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_


/*****************************************************************************/
#include <string>
#include "date.hpp"

class Student
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	enum Studying_Form
	{
		Budget,
		Contract
	};

/*-----------------------------------------------------------------*/

	Student (
			int _id
		,	const std::string &_name
		,	Date &_date
		,	Studying_Form _form
	);

	int getID() const;

	const std::string getName() const;

	Date getDate() const;

	Studying_Form getStudyingForm() const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const int m_id;
	const std::string m_sName;
	Date m_Date;
	Studying_Form m_StudyingForm;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Student(const Student &);
	Student & operator = (const Student &);

};

inline int Student::getID() const
{
	return m_id;
}

inline const std::string Student::getName() const
{
	return m_sName;
}

inline Date Student::getDate() const
{
	return m_Date;
}

inline Student::Studying_Form Student::getStudyingForm() const
{
	return m_StudyingForm;
}


/*****************************************************************************/


#endif // _STUDENT_HPP_
