#include "electroniclock.hpp"
#include <iostream>

/*****************************************************************************/

ElectronicLock::ElectronicLock(int _programmingCode)
	:m_programmingCode(_programmingCode), m_inProgrammingMode(true), m_set(IntegerSet())
{
}

ElectronicLock::~ElectronicLock()
{
	m_set.~IntegerSet();
}

ElectronicLock::ElectronicLock(const ElectronicLock &_elLock)
	: m_inProgrammingMode(_elLock.m_inProgrammingMode)
	, m_programmingCode(_elLock.m_programmingCode)
	, m_set(_elLock.m_set)
{
}

ElectronicLock & ElectronicLock::operator = (const ElectronicLock &_elLock)
{
	if (&_elLock == this)
		return *this;

	m_inProgrammingMode = _elLock.m_inProgrammingMode;
	m_programmingCode = _elLock.m_programmingCode;
	m_set = _elLock.m_set;
	
	return *this;
	
}

ElectronicLock::ElectronicLock(ElectronicLock && _el)
	: m_inProgrammingMode(_el.m_inProgrammingMode)
	, m_programmingCode(_el.m_programmingCode)
	, m_set(std::move(_el.m_set))
{
}

ElectronicLock & ElectronicLock::operator = (ElectronicLock &&_el)
{
	if (&_el == this)
		return *this;

	int newProgCode = _el.m_programmingCode;
	bool newInProgMode = _el.m_inProgrammingMode;

	_el.m_inProgrammingMode = m_inProgrammingMode;
	_el.m_programmingCode = m_programmingCode;

	m_inProgrammingMode = newInProgMode;
	m_programmingCode = newProgCode;


	m_set = (std::move(_el.m_set));

	return *this;
}

bool ElectronicLock::isInProgrammingMode() const
{
	return m_inProgrammingMode;
}

bool ElectronicLock::toggleProgrammingMode(int _programmingCode)
{
	if (m_programmingCode == _programmingCode)
	{
		m_inProgrammingMode = !m_inProgrammingMode;
		return true;
	}
	return false;
		
}

void ElectronicLock::registerCode(int _code)
{
	if (!m_inProgrammingMode)
		throw "Not in programming mode";
	else
		m_set.addKey(_code);
}

void ElectronicLock::unregisterCode(int _code)
{
	if (!m_inProgrammingMode)
		throw "Not in programming mode";
	else
		m_set.removeKey(_code);
}

void ElectronicLock::changeProgrammingCode(int _code)
{
	if (!m_inProgrammingMode)
		throw "Not in programming mode";
	else
		m_programmingCode = _code;
}

bool ElectronicLock::tryUnlocking(int _code)
{
	if (m_inProgrammingMode)
		throw "Not in operational mode";
	else
		return m_set.hasKey(_code);
}

bool ElectronicLock::tryUnlocking(const char* _code)
{
	int tCode;
	int nMaåched = sscanf(_code, "%d", &tCode);
	

	if (nMaåched != 1)
		throw "Bad format";
	else
		return m_set.hasKey(tCode);
		
}

bool ElectronicLock::operator ==(const ElectronicLock &_el)const
{
	return (m_programmingCode == _el.m_programmingCode
		 && m_set == _el.m_set);
}

bool ElectronicLock::operator !=(const ElectronicLock &_el)const
{
	return !(*this == _el);
}

void ElectronicLock::printL(std::ostream &_o)
{
	m_set.printS(_o);
}
/*****************************************************************************/

