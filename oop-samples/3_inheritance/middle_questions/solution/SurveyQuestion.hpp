#ifndef _SURVEY_Q_HPP_
#define _SURVEY_Q_HPP_

#include <string>

class SurveyQuestionVisitor;

class SurveyQuestion
{
/*--------------------------------------------------------------------------------------*/

public:

/*--------------------------------------------------------------------------------------*/

	virtual ~SurveyQuestion();

	virtual int getAnswersCount() const = 0;

	virtual std::string getAnswer(int _number) const = 0;

	virtual void accept(SurveyQuestionVisitor *_v) = 0;

	std::string getQuestion() const;

/*--------------------------------------------------------------------------------------*/

protected:

/*--------------------------------------------------------------------------------------*/

	SurveyQuestion(std::string const &_question);

/*--------------------------------------------------------------------------------------*/

private:

/*--------------------------------------------------------------------------------------*/

	std::string m_question;
};

inline std::string
SurveyQuestion::getQuestion() const
{
	return m_question;
}

#endif //_SURVEY_Q_HPP_