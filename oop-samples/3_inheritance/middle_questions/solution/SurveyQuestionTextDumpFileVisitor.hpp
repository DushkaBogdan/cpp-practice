#ifndef _SQTDFV_HPP_
#define _SQTDFV_HPP_

#include "SurveyQuestionVisitor.hpp"

class SurveyQuestionDumpFileVisitor
	:public SurveyQuestionVisitor
{
public:

	SurveyQuestionDumpFileVisitor(const char *_sPath);

	~SurveyQuestionDumpFileVisitor();

	void visit(ChoiceQuestion*_cQ) override;

	void visit(YesNoQuestion *_ynQ) override;

	void visit(RangeQuestion *_rQ) override;

private:

	char *m_sPath;
};

#endif //_SQTDFV_HPP_