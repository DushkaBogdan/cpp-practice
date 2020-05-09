#include "Controller.hpp"

#include "ChoiceQuestion.hpp"
#include "RangeQuestion.hpp"
#include "YesNoQuestion.hpp"

#include "SurveyQuestionTextDumpVisitor.hpp"
#include "SurveyQuestionTextDumpFileVisitor.hpp"
#include "SurveyQuestionBinarySerializationVisitor.hpp"

#include <iostream>

Controller::Controller()
{}

Controller::~Controller()
{
	int questionsSize = m_questions.size();
	for (int i = 0; i < questionsSize; i++)
		delete m_questions[i];

}

void Controller::addQuestion(SurveyQuestion *_pQ)
{
	m_questions.push_back(_pQ);
}

void Controller::runTest()
{
	ChoiceQuestion * chQ1 = new ChoiceQuestion("Choise Question 1");
	chQ1->addAnswer("Choise Question 1 : Answer1");
	chQ1->addAnswer("Choise Question 1 : Answer2");
	chQ1->addAnswer("Choise Question 1 : Answer3");
	addQuestion(chQ1);

	RangeQuestion *rQ1 = new RangeQuestion("Range Question 1", 1, 7, 2);
	rQ1->addAnswer("Range Question 1 Answer1", 1);
	rQ1->addAnswer("Range Question 1 Answer2", 3);
	rQ1->addAnswer("Range Question 1 Answer3", 5);
	rQ1->addAnswer("Range Question 1 Answer4", 7);
	addQuestion(rQ1);

	YesNoQuestion *ynQ1 = new YesNoQuestion("Yes No Question 1");
	addQuestion(ynQ1);
	
	YesNoQuestion *ynQ2 = new YesNoQuestion("Yes No Question 2");
	addQuestion(ynQ2);
	
	SurveyQuestionDumpVisitor v1(std::cout);

	SurveyQuestionDumpFileVisitor v2("myFile.txt");

	SurveyQuestionBinarySerializationVisitor v3("myBinaryFile.txt");

	v1.visit(chQ1);
	v1.visit(rQ1);
	v1.visit(ynQ1);
	v1.visit(ynQ2);

	v2.visit(chQ1);
	v2.visit(rQ1);
	v2.visit(ynQ1);
	v2.visit(ynQ2);

	v3.visit(chQ1);
	v3.visit(rQ1);
	v3.visit(ynQ1);
	v3.visit(ynQ2);
}