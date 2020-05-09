#include "IntegerSet.hpp"

IntegerSet::IntegerSet(int _size)
	:m_vector(IntegerVector(_size))
{}

IntegerSet::~IntegerSet()
{
	m_vector.~IntegerVector();
}

IntegerSet::IntegerSet(const IntegerSet &_set)
	: m_vector(_set.m_vector)
{}

IntegerSet & IntegerSet::operator = (const IntegerSet &_set)
{
	if (this == &_set)
		return *this;

	m_vector = _set.m_vector;
	return *this;
}

IntegerSet::IntegerSet(IntegerSet &&_s)
	:m_vector(std::move(_s.m_vector))
{
}

IntegerSet & IntegerSet::operator=(IntegerSet &&_s)
{
	if (this == &_s)
		return *this;

	m_vector =(std::move(_s.m_vector));
}

void IntegerSet::clear()
{
	m_vector.clear();
}

bool IntegerSet::isEmpty() const
{
	return m_vector.isEmpty();
}

bool IntegerSet::hasKey(int _key) const
{
	return m_vector.find(_key) != -1;
}

void IntegerSet::addKey(int _key)
{
	if( !hasKey(_key))
		m_vector.pushBack(_key);
}

void IntegerSet::removeKey(int _key)
{
	int position = m_vector.find(_key);
	if (position != -1)
		m_vector.removeAt(position);
}

bool IntegerSet::operator == (const IntegerSet &_s)const
{
	return m_vector == _s.m_vector;
}

bool IntegerSet::operator != (const IntegerSet &_s)const
{
	return m_vector != _s.m_vector;
}

void IntegerSet::printS(std::ostream &_o)
{
	m_vector.printV(_o);
}