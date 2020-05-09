#ifndef _YES_NO_Q_HPP_
#define _YES_NO_Q_HPP_

#include "SurveyQuestion.hpp"

class YesNoQuestion
	:public SurveyQuestion
{

/*--------------------------------------------------------------------------------------*/

public:

/*--------------------------------------------------------------------------------------*/

	YesNoQuestion(std::string const &);

	int getAnswersCount()const override;

	std::string getAnswer(int _number)const override;

	void accept(SurveyQuestionVisitor *_v) override;

/*--------------------------------------------------------------------------------------*/

private:

/*--------------------------------------------------------------------------------------*/

	YesNoQuestion(const YesNoQuestion &);
	YesNoQuestion & operator = (const YesNoQuestion&);

};

#endif //_YES_NO_Q_HPP_