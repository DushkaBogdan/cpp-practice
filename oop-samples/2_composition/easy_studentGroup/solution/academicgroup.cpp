#include "academicgroup.hpp"
#include "student.hpp"

/*****************************************************************************/

AcademicGroup::AcademicGroup(const std::string &_name)
	:m_sGroupName(_name)
{
	if (m_sGroupName.empty())
		throw "Group should have name!";
}

void AcademicGroup::addStudentToGroup(Student &_student)
{
	int groupSize = m_GroupList.size();
	for (int i = 0; i < groupSize; i++)
		if (m_GroupList[i]->getID() == _student.getID())
		{
			throw "Student with same ID is already in group!";
			return;
		}

	m_GroupList.push_back(&_student);
}

void AcademicGroup::kickStudent(Student &_student)
{
	int groupSize = m_GroupList.size();
	for (int i = 0; i < groupSize; i++)
		if (m_GroupList[i] == &_student)
		{
			auto it = m_GroupList.cbegin();
			m_GroupList.erase(it + i);
			return;
		}

	throw "Student can't be kicked out of group, cause he aint there!";

}

void AcademicGroup::setStudentLeader(Student &_student)
{
	int groupSize = m_GroupList.size();
	for (int i = 0; i < groupSize; i++)
		if (m_GroupList[i] == &_student)
		{
			m_StudentLeader = &_student;
			return;
		}
	throw "Student should be part of the group to become Leader!";
}

Student & AcademicGroup::getStudentByIndex(int _index)
{
	return *m_GroupList[_index];
}

void AcademicGroup::deleteAllstudents()
{
	for (int i = 0; i < getSizeOfGroup(); i++)
		delete m_GroupList[i];
}

/*****************************************************************************/
