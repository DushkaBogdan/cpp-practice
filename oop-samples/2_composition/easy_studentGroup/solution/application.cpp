#include "application.hpp"

#include "date.hpp"
#include "student.hpp"
#include "academicgroup.hpp"

#include <iostream>

/*****************************************************************************/


Application::Application ()
{}

/*****************************************************************************/


Application::~Application ()
{
	int groupsNumber = getGroupsNumber();
	for (int i = 0; i < groupsNumber; i++)
	{
		m_AcademicGroups[i]->deleteAllstudents();
		delete m_AcademicGroups[i];
	}
}


/*---------------------------------------------------------------------------*/

bool Application::addStudentToAcademicModel(Student &_student)
{
	int studentsID = _student.getID();

	if (m_AcademicAllStudentsID.count(studentsID))
	{
		throw "Student with Same ID is already in Model";
		return false;
	}

	m_AcademicAllStudentsID.insert(studentsID);
	return true;
}

int Application::getStudentsNumber()const
{
	return m_AcademicAllStudentsID.size();
}

void Application::addNewGroupToModel(AcademicGroup &_group)
{
	std::string name = _group.getGroupName();

	for (int i = 0; i < m_AcademicGroups.size(); i++)
		if (m_AcademicGroups[i]->getGroupName() == name)
			throw "Group with Such name is already existed!";

	m_AcademicGroups.push_back(&_group);
}

int Application::getGroupsNumber()const
{
	return m_AcademicGroups.size();
}

void Application::addStudentToGroup(Student &_student, AcademicGroup &_group)
{
	bool isInAcademicModel = addStudentToAcademicModel(_student);

	if (isInAcademicModel)
		_group.addStudentToGroup(_student);
}

/*---------------------------------------------------------------------------*/

/*****************************************************************************/


void
Application::generateTestModel ()
{
	Student *pStudent1 = new Student
	(
	11
	, "Sergey Ivanovych"
	, Date("1935/12/1")
	, Student::Studying_Form::Contract
	);

	Student *pStudent2 = new Student
	(
	12
	, "Artyom Evgenich"
	, Date("1995/08/17")
	, Student::Studying_Form::Budget
	);

	Student *pStudent3 = new Student
	(
	13
	, "Viktor Petrovich"
	, Date("2012/03/14")
	, Student::Studying_Form::Contract
	);

	Student *pStudent4 = new Student
	(
	14
	, "Sergey Ivanovych"
	, Date("1998/06/22")
	, Student::Studying_Form::Budget
	);

	Student *pStudent5 = new Student
	(
	15
	, "Vitya Razgelydyaevich"
	, Date(1995, 01, 01)
	, Student::Studying_Form::Budget
	);

	AcademicGroup* pGroup1 = new AcademicGroup("Group1");
	AcademicGroup* pGroup2 = new AcademicGroup("Group2");

	addNewGroupToModel(*pGroup1);
	addNewGroupToModel(*pGroup2);
	
	addStudentToGroup(*pStudent1, *pGroup1);
	addStudentToGroup(*pStudent2, *pGroup1);
	addStudentToGroup(*pStudent5, *pGroup1);
	pGroup1->setStudentLeader(*pStudent1);

	addStudentToGroup(*pStudent3, *pGroup2);
	addStudentToGroup(*pStudent4, *pGroup2);

}


/*****************************************************************************/


void
Application::printBudgetStudentsCount () const
{
	std::cout << "1. Budget Students" << std::endl;
	std::cout << "=======================================" << std::endl;

	int nTotalBudgetStudents = 0;
	
	int groupsNumber = getGroupsNumber();
	for (int i = 0; i < groupsNumber; i++)
	{
		int sizeGroup = m_AcademicGroups[i]->getSizeOfGroup();
		for (int j = 0; j < sizeGroup; j++)
			if (m_AcademicGroups[i]->getStudentByIndex(j).getStudyingForm() ==
				Student::Studying_Form::Budget)
				nTotalBudgetStudents++;
	}

	std::cout << "Total - " << nTotalBudgetStudents << std::endl << std::endl;
}


/*****************************************************************************/


void
Application::printContractStudentsCount () const
{
	std::cout << "2. Contract Students" << std::endl;
	std::cout << "=======================================" << std::endl;

	int nTotalContractStudents = 0;
		
	int groupsNumber = getGroupsNumber();
	for (int i = 0; i < groupsNumber; i++)
	{
		int sizeGroup = m_AcademicGroups[i]->getSizeOfGroup();
		for (int j = 0; j < sizeGroup; j++)
			if (m_AcademicGroups[i]->getStudentByIndex(j).getStudyingForm() ==
				Student::Studying_Form::Contract)
				nTotalContractStudents++;
	}

	std::cout << "Total - " << nTotalContractStudents << std::endl << std::endl;
}


/*****************************************************************************/


void
Application::printStudentsBornFirstDayOfMonth () const
{
	std::cout << "3. Students born on first day of a month" << std::endl;
	std::cout << "=======================================" << std::endl;

	int groupsNumber = getGroupsNumber();
	for (int i = 0; i < groupsNumber; i++)
	{
		int sizeGroup = m_AcademicGroups[i]->getSizeOfGroup();
		for (int j = 0; j < sizeGroup; j++)
			if (m_AcademicGroups[i]->getStudentByIndex(j).getDate().getDay() == 1)
				std::cout << "Student " << m_AcademicGroups[i]->getStudentByIndex(j).getName() << std::endl;
	}

	std::cout << std::endl;
}


/*****************************************************************************/


void 
Application::printEldestStudent () const
{
	std::cout << "4. Eldest student" << std::endl;
	std::cout << "=======================================" << std::endl;

	Student *eldestStudent = &m_AcademicGroups[0]->getStudentByIndex(0);
	
	int groupsNumber = getGroupsNumber();
	for (int i = 0; i < groupsNumber; i++)
	{
		int sizeGroup = m_AcademicGroups[i]->getSizeOfGroup();
		for (int j = 0; j < sizeGroup; j++)
			if (m_AcademicGroups[i]->getStudentByIndex(j).getDate() < eldestStudent->getDate())
				eldestStudent = &m_AcademicGroups[i]->getStudentByIndex(j);
	}

	std::cout << eldestStudent->getName() << " is the eldest Student \n"
		<< "he was born at "
		<< eldestStudent->getDate().getYear() << "/"
		<< eldestStudent->getDate().getMonth() << "/"
		<< eldestStudent->getDate().getDay() << "/ \n"
		<< "form of Education is: " << (eldestStudent->getStudyingForm() == Student::Budget ? "Budget" : "Contract") << '\n'
		<< eldestStudent->getID() << ": his ID";


	std::cout << std::endl;
}


/*****************************************************************************/
