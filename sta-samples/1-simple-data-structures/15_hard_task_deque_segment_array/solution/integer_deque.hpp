#ifndef _INTEGER_DEQUE_HPP_
#define _INTEGER_DEQUE_HPP_

struct IntegerDeque
{
	//  оличество €чеек в массиве-директории
	int m_directorySize;

	//  оличество €чеек в каждом блоке данных
	int m_blockSize;

	// ћассив-директори€: указатели на блоки данных
	int ** m_pDirectory;

	// »ндексы верхней и нижней позиции из зан€тых €чеек в директории
	int m_frontBlockIndex, m_backBlockIndex;

	//  оличество зан€тых элементов в первом и последнем блоках
	int m_frontUsed, m_backUsed;
};


void IntegerDequeCreate(IntegerDeque &_dq, int _directorySize = 3, int _blockSize = 3);

void IntegerDequeClear(IntegerDeque &_dq);

void IntegerDequeDestroy(IntegerDeque &_dq);

bool IntegerDequeIsEmpty(const IntegerDeque &_dq);

bool IntegerDequeBackIsFull(const IntegerDeque &_dq);

bool IntegerDequeFrontIsFull(const IntegerDeque &_dq);

void IntegerDequePushFront(IntegerDeque &_dq, int _data);

void IntegerDequePushBack(IntegerDeque &_dq, int _data);

void IntegerDequePopFront(IntegerDeque &_dq);

void IntegerDequePopBack(IntegerDeque &_dq);

int IntegerDequeSize(const IntegerDeque &_dq);

int IntegerDequeFront(const IntegerDeque &_dq);

int IntegerDequeBack(const IntegerDeque &_dq);

#endif //_INTEGER_DEQUE_HPP_



