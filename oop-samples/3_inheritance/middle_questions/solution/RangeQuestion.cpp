#include "RangeQuestion.hpp"
#include "SurveyQuestionVisitor.hpp"

RangeQuestion::RangeQuestion
	(
	std::string const &_question,
	int _first,
	int _last,
	int _step
	):
	SurveyQuestion(_question),
	m_beginning(_first),
	m_end(_last),
	m_step(_step)
{
	if (_last <= _first)
		throw "Beginning Value should be less than the Last one";
}
int RangeQuestion::getAnswersCount() const
{
	return m_answers.size();
}

std::string RangeQuestion::getAnswer(int _number) const
{

	if (m_answers.count(_number) == 0)
		throw "That number is not exist!";
	auto it = m_answers.find(_number);
	return it->second;
}

void RangeQuestion::accept(SurveyQuestionVisitor *_v)
{
	_v->visit(this);
}

void RangeQuestion::addAnswer(std::string const &_answer, int _number)
{
	if (m_byNames.count(_answer))
		throw "That answer is already exists";
	if (m_answers.count(_number))
		throw "Answer is already in base";

	m_answers[_number] =_answer;
	m_byNames[_answer] = _number;

}