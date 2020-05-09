#ifndef _SUR_Q_VISITOR_HPP_
#define _SUR_Q_VISITOR_HPP_


class ChoiceQuestion;
class YesNoQuestion;
class RangeQuestion;

class SurveyQuestionVisitor
{
public:

	virtual void visit(ChoiceQuestion*_cQ) = 0;

	virtual void visit(YesNoQuestion *_ynQ) = 0;

	virtual void visit(RangeQuestion *_rQ) = 0;
};

#endif //_SUR_Q_VISITOR_HPP_