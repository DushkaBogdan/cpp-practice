#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

#include <vector>

class SurveyQuestion;

class Controller
{
/*--------------------------------------------------------------------------------------*/

public:

/*--------------------------------------------------------------------------------------*/

	Controller();

	~Controller();

	void addQuestion(SurveyQuestion *_pQ);

	void runTest();

/*--------------------------------------------------------------------------------------*/

private:

/*--------------------------------------------------------------------------------------*/

	Controller(const Controller&);
	Controller &operator = (const Controller&);

/*--------------------------------------------------------------------------------------*/

private:

/*--------------------------------------------------------------------------------------*/

	std::vector<SurveyQuestion*>m_questions;

};

#endif //_CONTROLLER_HPP_