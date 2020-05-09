#include "SurveyQuestionTextDumpVisitor.hpp"

#include "RangeQuestion.hpp"
#include "YesNoQuestion.hpp"
#include "ChoiceQuestion.hpp"

SurveyQuestionDumpVisitor::SurveyQuestionDumpVisitor(std::ostream &_o)
	:m_ostream(_o)
{}

void SurveyQuestionDumpVisitor::visit(ChoiceQuestion*_cQ)
{
	m_ostream << _cQ->getQuestion() << std::endl;

	for (int i = 0; i < _cQ->getAnswersCount(); i++)
		m_ostream << _cQ->getAnswer(i) << "; ";

	m_ostream << std::endl;
}

void SurveyQuestionDumpVisitor::visit(YesNoQuestion *_ynQ)
{
	m_ostream << _ynQ->getQuestion() << std::endl;

	for (int i = 0; i < 2; i++)
		m_ostream << _ynQ->getAnswer(i) << "; ";

	m_ostream << std::endl;
}

void SurveyQuestionDumpVisitor::visit(RangeQuestion *_rQ)
{
	m_ostream << _rQ->getQuestion() << std::endl;

	int begin = _rQ->getBegin();
	int end = _rQ->getEnd();
	int step = _rQ->getStep();

	for (int i = begin; i <= end; i += step)
		m_ostream << _rQ->getAnswer(i) << "; ";

	m_ostream << std::endl;
}