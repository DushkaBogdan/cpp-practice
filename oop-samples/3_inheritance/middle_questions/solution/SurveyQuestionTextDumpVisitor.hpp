#ifndef _SQTDV_HPP_
#define _SQTDV_HPP_

#include "SurveyQuestionVisitor.hpp"
#include <ostream>

class SurveyQuestionDumpVisitor
	:public SurveyQuestionVisitor
{
public:

	SurveyQuestionDumpVisitor(std::ostream &_o);

	void visit(ChoiceQuestion*_cQ) override;

	void visit(YesNoQuestion *_ynQ) override;

	void visit(RangeQuestion *_rQ) override;

private:

	std::ostream &m_ostream;
};

#endif //_SQTDV_HPP_