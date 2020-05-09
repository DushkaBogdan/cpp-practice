#include "integer_vector.hpp"
#include "multi_map.hpp"
#include "vld.h"

#include <iostream>

struct CustomerVisitTime
{
	short m_startHour, m_startMinute;
	short m_finishHour, m_finishMinute;
};

void CustomerInit(
	CustomerVisitTime &_v,
	short _startHour,
	short _startMinute,
	short _finishHour,
	short _finishMinute)
{
	_v.m_startHour = _startHour;
	_v.m_startMinute = _startMinute;
	_v.m_finishHour = _finishHour;
	_v.m_finishMinute = _finishMinute;
}

void CalculateTime(const CustomerVisitTime &_v, short &_start, short &_finish)
{
	_start = _v.m_startHour * 60 + _v.m_startMinute;
	_finish = _v.m_finishHour * 60 + _v.m_finishMinute;
}

void IntegerMapPrint(const IntegerMap &_map)
{
	for (int i = 0; i < _map.m_keys.m_nUsed; i++)
	{
		std::cout << (i + 1) << ": Key = " << _map.m_keys.m_pData[i] << "; "
			<< "Value = " << _map.m_values.m_pData[i] << std::endl;
	}
}

void Insertion(IntegerMap &map, short start, short finish)
{
	for (int i = 0; i < (map.m_keys.m_nUsed - 1); i++) //ищем позицию (i) отрезка времени соответствующему start
	{
		//а соответствует он тогда когда лежит на промежутке между началом тридцатиминутки (start больше начала) и началом следующей (start меньше следующего начала)
		if (start >= map.m_keys.m_pData[i] && start < map.m_keys.m_pData[i + 1])
		{
			for (int j = 0; j < (map.m_keys.m_nUsed - 1); j++)//ищем позицию (j) отрезка времени соответствующему finish
			{
				//Также и с finish
				if (finish >= map.m_keys.m_pData[j] && finish < map.m_keys.m_pData[j + 1])
				{
					//Клиент уходит до полуночи
					if (finish > start)
					{
						for (int k = i; k <= j; k++)
						{
							IntegerMapInsertKey(map, map.m_keys.m_pData[k], 1);
						}
					}
					//Клиент уходит после полуночи
					else if (finish < start)
					{
						for (int k = 0; k <= j; k++)
						{
							IntegerMapInsertKey(map, map.m_keys.m_pData[k], 1);
						}

						for (int z = i; z < map.m_keys.m_nUsed; z++)
						{
							IntegerMapInsertKey(map, map.m_keys.m_pData[z], 1);
						}
					}
				}
			}
		}
	}
}
	
int FindPrimeTime(const IntegerMap &_map)
{
	int max = 0;
	int maxIndex = 0;

	for (int i = 0; i < _map.m_values.m_nUsed; i++)
	{
		if (_map.m_values.m_pData[i] > max)
		{
			max = _map.m_values.m_pData[i];
			maxIndex = i;
		}
	}
	return _map.m_keys.m_pData[maxIndex];
}

int main()
{
	IntegerMap *map = IntegerMapCreate();

	short time = 0;
	for (int i = 0; i < 48; i++)
	{
		IntegerMapInsertKey(*map, time, 0);
		time += 30;
	}

	for (int i = 0; i < 20; i++)
	{
		short start = 0, finish = 0;

		CustomerVisitTime Misha1;
		CustomerInit(
			Misha1,
			rand() % 24,
			rand() % 60,
			rand() % 24,
			rand() % 60);

		CalculateTime(Misha1, start, finish);

		/*std::cout << "Misha1.m_startHour: " << Misha1.m_startHour
			<< "; " << "Misha1.m_startMinute: " << Misha1.m_startMinute
			<< "; " << "Misha1.m_finishHour: " << Misha1.m_finishHour
			<< "; " << "Misha1.m_finishMinute: " << Misha1.m_finishMinute
			<< std::endl << "start: " << start << "; " << "finish: " << finish << std::endl;*/

		

		Insertion(*map, start, finish);

		/*IntegerMapPrint(*map);
		std::cout << "=====================" << std::endl;*/
	}
	
	IntegerMapPrint(*map);

	std::cout << "=====================" << std::endl;

	std::cout << "Prime Time 30 mins from: "
			  << (FindPrimeTime(*map) / 60) << " hours; " 
			  << (FindPrimeTime(*map) % 60) << " minutes. "
			  << std::endl;

	std::cout << "=====================" << std::endl;

	
	IntegerMapDestroy(map);
}