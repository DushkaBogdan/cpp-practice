#include "integer_deque.hpp"
#include <cassert>

void IntegerDequeCreate(IntegerDeque &_dq, int _directorySize, int _bLockSize)
{
	//Определили размер директории
	_dq.m_directorySize = _directorySize;
	//Создали директорию фиксированного размера - массив указателей на блоки
	_dq.m_pDirectory = new int*[_directorySize];
	//Индексы директории, указывающие на начальный и конечный индекс очереди
	_dq.m_frontBlockIndex = _dq.m_backBlockIndex = 1; /*===============================================*/

	//Индексы начала и конца очереди обнулены
	_dq.m_backUsed = _dq.m_frontUsed = 1; /*===============================================*/
	//Размер блока фиксированный
	_dq.m_blockSize = _bLockSize;

	
}

void IntegerDequeClear(IntegerDeque &_dq)
{
	if (!IntegerDequeIsEmpty(_dq))
	{
		for (int i = _dq.m_frontBlockIndex; i < _dq.m_backBlockIndex +1; i++)
			delete[] _dq.m_pDirectory[i];
	}
	_dq.m_backUsed = _dq.m_frontUsed = 1; /*===============================================*/
	_dq.m_frontBlockIndex = _dq.m_backBlockIndex =  1;/*===============================================*/
}

void IntegerDequeDestroy(IntegerDeque &_dq)
{
	IntegerDequeClear(_dq);
	delete[] _dq.m_pDirectory;
}

bool IntegerDequeIsEmpty(const IntegerDeque &_dq)
{
	//Очередь пуста, если индексы директории совпадают, а индексы очереди равны (при начале работы)
	return (((_dq.m_frontUsed == _dq.m_backUsed)
		&& (_dq.m_frontBlockIndex == _dq.m_backBlockIndex))
		|| (((_dq.m_backUsed - _dq.m_frontUsed) == 1) // при начале работы - индексы сдвигаются на 1 относительно друг друга (чтобы не перекрыть вставляемое значение)
		&& (_dq.m_frontBlockIndex == _dq.m_backBlockIndex))
			);
}

bool IntegerDequeBackIsFull(const IntegerDeque &_dq)
{
	return ((_dq.m_backBlockIndex == _dq.m_directorySize - 1)
		&& (_dq.m_backUsed == _dq.m_blockSize));
}

bool IntegerDequeFrontIsFull(const IntegerDeque &_dq)
{
	return ((_dq.m_frontBlockIndex == 0)
		&& (_dq.m_frontUsed == -1));
}

void IntegerDequePushBack(IntegerDeque &_dq, int _data)
{
	assert(!IntegerDequeBackIsFull(_dq));

	if (IntegerDequeIsEmpty(_dq))
	{
		_dq.m_pDirectory[_dq.m_backBlockIndex] = new int[_dq.m_blockSize];
		_dq.m_pDirectory[_dq.m_backBlockIndex][_dq.m_backUsed] = _data;
		++_dq.m_backUsed;
		--_dq.m_frontUsed;
	}
	else if (_dq.m_backUsed == _dq.m_blockSize)
	{
		_dq.m_pDirectory[++_dq.m_backBlockIndex] = new int[_dq.m_blockSize];
		_dq.m_backUsed = 0;
		_dq.m_pDirectory[_dq.m_backBlockIndex][_dq.m_backUsed] = _data;
		++_dq.m_backUsed;
	}
	else
	{
		_dq.m_pDirectory[_dq.m_backBlockIndex][_dq.m_backUsed] = _data;
		++_dq.m_backUsed;
	}
}

void IntegerDequePushFront(IntegerDeque &_dq, int _data)
{
	assert(!IntegerDequeFrontIsFull(_dq));

	if (IntegerDequeIsEmpty(_dq))
	{
		_dq.m_pDirectory[_dq.m_frontBlockIndex] = new int[_dq.m_blockSize];
		_dq.m_pDirectory[_dq.m_frontBlockIndex][_dq.m_frontUsed] = _data;
		--_dq.m_frontUsed;
		++_dq.m_backUsed;
	}
	else if (_dq.m_frontUsed == -1)
	{
		_dq.m_pDirectory[--_dq.m_frontBlockIndex] = new int[_dq.m_blockSize];
		_dq.m_frontUsed = _dq.m_blockSize - 1;
		_dq.m_pDirectory[_dq.m_frontBlockIndex][_dq.m_frontUsed] = _data;
		--_dq.m_frontUsed;
	}
	else
	{
		_dq.m_pDirectory[_dq.m_frontBlockIndex][_dq.m_frontUsed] = _data;
		--_dq.m_frontUsed;
	}

}

void IntegerDequePopFront(IntegerDeque &_dq)
{
	assert(!IntegerDequeIsEmpty(_dq));

	if (_dq.m_frontUsed == _dq.m_blockSize -2)
	{
		delete[] _dq.m_pDirectory[_dq.m_frontBlockIndex];
		++_dq.m_frontBlockIndex;
		_dq.m_frontUsed = -1;
	}
	else
	{
		_dq.m_pDirectory[_dq.m_frontBlockIndex][_dq.m_frontUsed + 1] = 999;
		++_dq.m_frontUsed;
	}
}

void IntegerDequePopBack(IntegerDeque &_dq)
{
	assert(!IntegerDequeIsEmpty(_dq));

	if (_dq.m_backUsed == 1)
	{
		delete[] _dq.m_pDirectory[_dq.m_backBlockIndex];
		--_dq.m_backBlockIndex;
		_dq.m_backUsed = _dq.m_blockSize;
	}
	else
	{
		_dq.m_pDirectory[_dq.m_backBlockIndex][_dq.m_backUsed-1] = 999;
		--_dq.m_backUsed;
	}
}

int IntegerDequeSize(const IntegerDeque &_dq);

int IntegerDequeFront(const IntegerDeque &_dq)
{
	assert(!IntegerDequeIsEmpty(_dq));

	return _dq.m_pDirectory[_dq.m_frontBlockIndex][_dq.m_frontUsed + 1];
}

int IntegerDequeBack(const IntegerDeque &_dq)
{
	assert(!IntegerDequeIsEmpty(_dq));

	return _dq.m_pDirectory[_dq.m_backBlockIndex][_dq.m_backUsed - 1];
}