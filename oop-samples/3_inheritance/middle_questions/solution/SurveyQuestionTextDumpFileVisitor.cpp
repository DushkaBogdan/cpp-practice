#include "SurveyQuestionTextDumpFileVisitor.hpp"

#include "RangeQuestion.hpp"
#include "YesNoQuestion.hpp"
#include "ChoiceQuestion.hpp"

#include <fstream>


char * strCP(const char *_s)
{
	int size = strlen(_s);
	char *buff = new char[size + 1];
	strcpy_s(buff, (size + 1), _s);

	return buff;
}

SurveyQuestionDumpFileVisitor::SurveyQuestionDumpFileVisitor(const char *_sPath)
{
	m_sPath = strCP(_sPath);
}

SurveyQuestionDumpFileVisitor::~SurveyQuestionDumpFileVisitor()
{
	delete m_sPath;
}

void SurveyQuestionDumpFileVisitor::visit(ChoiceQuestion*_cQ)
{
	std::ofstream fOut;

	fOut.open(m_sPath, std::ofstream::app);

	if (!fOut.is_open())
	{
		throw "Can't open file";
	}
	else
	{
		fOut << _cQ->getQuestion() << '\n';
		
		for (int i = 0; i < _cQ->getAnswersCount(); i++)
			fOut << _cQ->getAnswer(i) << '\n';

		fOut << '\n';
	}

	fOut.close();
}

void SurveyQuestionDumpFileVisitor::visit(YesNoQuestion *_ynQ)
{

	std::ofstream fOut;

	fOut.open(m_sPath, std::ofstream::app);

	if (!fOut.is_open())
	{
		throw "Can't open file";
	}
	else
	{
		fOut << _ynQ->getQuestion() << '\n';

		for (int i = 0; i < 2; i++)
			fOut << _ynQ->getAnswer(i) << '\n';

		fOut << '\n';
	}

	fOut.close();
}

void SurveyQuestionDumpFileVisitor::visit(RangeQuestion *_rQ)
{
	std::ofstream fOut;

	fOut.open(m_sPath, std::ofstream::app);

	if (!fOut.is_open())
	{
		throw "Can't open file";
	}
	else
	{
		fOut << _rQ->getQuestion() << '\n';

		int begin = _rQ->getBegin();
		int end = _rQ->getEnd();
		int step = _rQ->getStep();

		for (int i = begin; i <= end; i += step)
			fOut << _rQ->getAnswer(i) << '\n';

		fOut << '\n';
	}

	fOut.close();
}