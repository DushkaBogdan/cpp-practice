#ifndef _INTEGER_VECTOR_HPP_
#define _INTEGER_VECTOR_HPP_

#include <iostream>

class IntegerVector
{
/*------------------------------------------------------------------*/

private:

	int m_nAllocated, m_nUsed;
	int* m_pData;

/*------------------------------------------------------------------*/
	
private:

	void Grow();

/*------------------------------------------------------------------*/

public:

	IntegerVector(int _size = 10);

	IntegerVector(const IntegerVector &_v);
	IntegerVector & operator =(const IntegerVector &_v);

	IntegerVector(IntegerVector &&_v);
	IntegerVector & operator =(IntegerVector &&_v);

	~IntegerVector();

	void clear();
	bool isEmpty() const;

	int getSize() const;

	void pushBack(int _value);

	void popBack();
	void popFront();

	int find(int _value) const;

	void removeAt(int _index);

	bool operator == (const IntegerVector &_v)const;

	bool operator != (const IntegerVector &_v)const;

	void printV(std::ostream &_o);
/*------------------------------------------------------------------*/
};

inline int IntegerVector::getSize() const
{
	return m_nUsed;
}

#endif //_INTEGER_VECTOR_HPP_

