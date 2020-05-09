#ifndef _CHOICE_Q_HPP_
#define _CHOICE_Q_HPP_

#include "SurveyQuestion.hpp"
#include <vector>
#include <unordered_map>

class ChoiceQuestion
	:public SurveyQuestion
{
/*--------------------------------------------------------------------------------------*/

public:

/*--------------------------------------------------------------------------------------*/

	ChoiceQuestion(std::string const &_question);

	int getAnswersCount() const override;

	std::string getAnswer(int _number) const override;

	void accept(SurveyQuestionVisitor *_v) override;

	void addAnswer(std::string const &_answer);

/*--------------------------------------------------------------------------------------*/

private:

/*--------------------------------------------------------------------------------------*/

	ChoiceQuestion(const ChoiceQuestion &);
	ChoiceQuestion & operator = (const ChoiceQuestion &);

/*--------------------------------------------------------------------------------------*/

private:

/*--------------------------------------------------------------------------------------*/

	std::vector<std::string> m_answers;

	std::unordered_map<std::string, int> m_byNames;
};

#endif //_CHOICE_Q_HPP_