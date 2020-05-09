#include "YesNoQuestion.hpp"
#include "SurveyQuestionVisitor.hpp"

YesNoQuestion::YesNoQuestion(std::string const &_question)
	:SurveyQuestion(_question)
{}

int YesNoQuestion::getAnswersCount()const
{
	return 2;
}

std::string YesNoQuestion::getAnswer(int _number)const
{
	if (_number != 0 && _number != 1)
		throw "Number YesNoQuestion is out of range";
	else
		return (_number == 0 ? "Yes" : "No");
	
	return nullptr;
}

void YesNoQuestion::accept(SurveyQuestionVisitor *_v)
{
	_v->visit(this);
}