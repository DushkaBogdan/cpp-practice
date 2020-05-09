#include "ChoiceQuestion.hpp"
#include "SurveyQuestionVisitor.hpp"

ChoiceQuestion::ChoiceQuestion(std::string const &_question)
	:SurveyQuestion(_question)
{}

int ChoiceQuestion::getAnswersCount() const
{
	return m_answers.size();
}

//========================================================================================
std::string ChoiceQuestion::getAnswer(int _number) const
{
	if (_number < 0 && _number > m_answers.size())
		throw "Number of ChoiceAnswer is out of range";
	else
		return m_answers[_number];
	return nullptr;
}

void ChoiceQuestion::accept(SurveyQuestionVisitor *_v)
{
	_v->visit(this);
}

void ChoiceQuestion::addAnswer(std::string const &_answer)
{
	if (m_byNames.count(_answer))
		throw "Such answer is already exists";

	m_byNames[_answer] = m_answers.size();

	m_answers.push_back(_answer);
}