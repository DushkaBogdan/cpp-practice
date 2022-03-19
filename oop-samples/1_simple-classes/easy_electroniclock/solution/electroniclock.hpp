#ifndef _ELECTRONICLOCK_HPP_
#define _ELECTRONICLOCK_HPP_

/*****************************************************************************/

#include "IntegerSet.hpp"

class ElectronicLock
{

/*-----------------------------------------------------------------*/

private:

	int m_programmingCode;

	bool m_inProgrammingMode;

	IntegerSet m_set;

/*------------------------------------------------------------------*/

public:

	ElectronicLock(int _programmingCode);

	ElectronicLock(const ElectronicLock &_elLock);
	ElectronicLock & operator = (const ElectronicLock &_elLock);

	ElectronicLock(ElectronicLock && _el);
	ElectronicLock & operator = (ElectronicLock &&_el);

	~ElectronicLock();

	bool isInProgrammingMode() const;

	bool toggleProgrammingMode(int _programmingCode);

	void registerCode(int);

	void unregisterCode(int);

	void changeProgrammingCode(int);

	bool tryUnlocking(int);

	bool tryUnlocking(const char*);

	bool operator ==(const ElectronicLock &_el)const;

	bool operator !=(const ElectronicLock &_el)const;

	void printL(std::ostream &_o);
	
/*------------------------------------------------------------------*/

};


/*****************************************************************************/

#endif //  _ELECTRONICLOCK_HPP_
