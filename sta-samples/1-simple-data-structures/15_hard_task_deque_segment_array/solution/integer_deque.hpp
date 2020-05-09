#ifndef _INTEGER_DEQUE_HPP_
#define _INTEGER_DEQUE_HPP_

struct IntegerDeque
{
	// ���������� ����� � �������-����������
	int m_directorySize;

	// ���������� ����� � ������ ����� ������
	int m_blockSize;

	// ������-����������: ��������� �� ����� ������
	int ** m_pDirectory;

	// ������� ������� � ������ ������� �� ������� ����� � ����������
	int m_frontBlockIndex, m_backBlockIndex;

	// ���������� ������� ��������� � ������ � ��������� ������
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



