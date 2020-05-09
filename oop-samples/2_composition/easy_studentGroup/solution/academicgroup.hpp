#ifndef _ACADEMICGROUP_HPP_
#define _ACADEMICGROUP_HPP_

/*****************************************************************************/

#include <string>
#include <vector>

class Student;

/*****************************************************************************/


class AcademicGroup
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	AcademicGroup(const std::string &_name);

	std::string getGroupName() const;

	Student & getStudentLeader() const;

	void setStudentLeader(Student &_student);

	void addStudentToGroup(Student &_student);

	void kickStudent(Student &_student);

	int getSizeOfGroup()const;

	Student & getStudentByIndex(int _index);

	void deleteAllstudents();

/*-----------------------------------------------------------------*/

private:

	const std::string m_sGroupName;

	std::vector<Student*>m_GroupList;

	Student *m_StudentLeader;

/*-----------------------------------------------------------------*/

private:

	AcademicGroup(const AcademicGroup &);
	AcademicGroup & operator = (const AcademicGroup &);

};


inline std::string AcademicGroup::getGroupName() const
{
	return m_sGroupName;
}

inline Student & AcademicGroup::getStudentLeader() const
{
	return *m_StudentLeader;
}

inline int AcademicGroup::getSizeOfGroup()const
{
	return m_GroupList.size();
}


/*****************************************************************************/

#endif // _ACADEMICGROUP_HPP_
