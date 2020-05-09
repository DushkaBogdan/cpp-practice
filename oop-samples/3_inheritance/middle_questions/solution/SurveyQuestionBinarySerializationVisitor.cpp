#include "SurveyQuestionBinarySerializationVisitor.hpp"

#include "RangeQuestion.hpp"
#include "YesNoQuestion.hpp"
#include "ChoiceQuestion.hpp"

#include <fstream>


char * strCP1(const char *_s)
{
	int size = strlen(_s);
	char *buff = new char[size + 1];
	strcpy_s(buff, (size + 1), _s);

	return buff;
}

SurveyQuestionBinarySerializationVisitor::
SurveyQuestionBinarySerializationVisitor(const char *_sPath)
{
	m_sPath = strCP1(_sPath);
}

SurveyQuestionBinarySerializationVisitor::
~SurveyQuestionBinarySerializationVisitor()
{
	delete m_sPath;
}

void SurveyQuestionBinarySerializationVisitor::
visit(ChoiceQuestion*_cQ)
{
	std::ofstream fOut;

	fOut.open(m_sPath, std::ofstream::app);

	if (!fOut.is_open())
	{
		throw "Can't open file";
	}
	else
	{
		fOut.write((char*)&_cQ, sizeof(ChoiceQuestion));
	}

	fOut.close();
}

void SurveyQuestionBinarySerializationVisitor::
visit(YesNoQuestion *_ynQ)
{

	std::ofstream fOut;

	fOut.open(m_sPath, std::ofstream::app);

	if (!fOut.is_open())
	{
		throw "Can't open file";
	}
	else
	{
		fOut.write((char*)&_ynQ, sizeof(YesNoQuestion));
	}

	fOut.close();
}

void SurveyQuestionBinarySerializationVisitor::
visit(RangeQuestion *_rQ)
{
	std::ofstream fOut;

	fOut.open(m_sPath, std::ofstream::app);

	if (!fOut.is_open())
	{
		throw "Can't open file";
	}
	else
	{
		fOut.write((char*)&_rQ, sizeof(RangeQuestion));
	}

	fOut.close();
}