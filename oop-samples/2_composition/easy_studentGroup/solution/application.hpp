#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

/*****************************************************************************/

#include <set>
#include <vector>

class Student;
class AcademicGroup;
class Date;

class Application
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Application ();

	~ Application ();

	void generateTestModel ();

	void printBudgetStudentsCount () const;

	void printContractStudentsCount () const;

	void printStudentsBornFirstDayOfMonth () const;

	void printEldestStudent () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Application ( const Application & );
	Application & operator = ( const Application & );

/*-----------------------------------------------------------------*/

	std::set<int>m_AcademicAllStudentsID;

	std::vector<AcademicGroup*>m_AcademicGroups;

/*-----------------------------------------------------------------*/

	bool addStudentToAcademicModel(Student &_student);

	int getStudentsNumber()const;

	void addNewGroupToModel(AcademicGroup &_group );

	int getGroupsNumber()const;

	void addStudentToGroup(Student &_student, AcademicGroup &_group);

};


/*****************************************************************************/

#endif //  _APPLICATION_HPP_
