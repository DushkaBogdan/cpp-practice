#ifndef _RANGE_Q_HPP_
#define _RANGE_Q_HPP_

#endif //_RANGE_Q_HPP_

#include "SurveyQuestion.hpp"

#include <unordered_map>
#include <map>

class RangeQuestion
	:public SurveyQuestion
{
/*--------------------------------------------------------------------------------------*/

public:

/*--------------------------------------------------------------------------------------*/

	RangeQuestion
	(
		std::string const &_question, 
		int _first,
		int _last,
		int _step
	);

	virtual int getAnswersCount() const override;

	virtual std::string getAnswer(int _number) const override;

	virtual void accept(SurveyQuestionVisitor *_v) override;

	void addAnswer(std::string const &_answer, int _value);

	int getBegin() const { return m_beginning; };
	int getEnd() const { return m_end; };
	int getStep() const { return m_step; };

/*--------------------------------------------------------------------------------------*/

private:

/*--------------------------------------------------------------------------------------*/

	RangeQuestion(const RangeQuestion &);
	RangeQuestion & operator = (const RangeQuestion &);

/*--------------------------------------------------------------------------------------*/

private:

/*--------------------------------------------------------------------------------------*/

	int m_beginning, m_end, m_step;

	std::map <int, std::string>m_answers;

	std::unordered_map <std::string, int>m_byNames;

	
};