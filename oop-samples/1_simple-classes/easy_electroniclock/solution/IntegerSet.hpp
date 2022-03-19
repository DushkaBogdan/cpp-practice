#ifndef _INTEGER_SET_HPP_
#define _INTEGER_SET_HPP_

#include "IntegerVector.hpp"

class IntegerSet
{
/*------------------------------------------------------------------*/

private:

	IntegerVector m_vector;

/*------------------------------------------------------------------*/

public:

	IntegerSet(int _size = 10);
	~IntegerSet();
	
	IntegerSet(const IntegerSet &_set);
	IntegerSet & operator = (const IntegerSet &_set);

	IntegerSet(IntegerSet &&_s);
	IntegerSet &operator=(IntegerSet &&_s);

	void clear();

	bool isEmpty() const;

	int getSize() const;

	bool hasKey(int _key) const;

	void addKey(int _key);

	void removeKey(int _key);

	bool operator == (const IntegerSet &_v)const;

	bool operator != (const IntegerSet &_v)const;

	void printS(std::ostream &_o);
	
/*------------------------------------------------------------------*/	
};

inline int IntegerSet::getSize() const
{
	return m_vector.getSize();
}

#endif // _INTEGER_SET_HPP_


