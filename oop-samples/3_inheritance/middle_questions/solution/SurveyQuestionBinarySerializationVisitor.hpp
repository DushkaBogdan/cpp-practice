#ifndef _SQBSV_HPP_
#define _SQBSV_HPP_

#include "SurveyQuestionVisitor.hpp"

class SurveyQuestionBinarySerializationVisitor
	:public SurveyQuestionVisitor
{
public:

	SurveyQuestionBinarySerializationVisitor(const char *_sPath);

	~SurveyQuestionBinarySerializationVisitor();

	void visit(ChoiceQuestion*_cQ) override;

	void visit(YesNoQuestion *_ynQ) override;

	void visit(RangeQuestion *_rQ) override;

private:

	char *m_sPath;
};

#endif //_SQBSV_HPP_