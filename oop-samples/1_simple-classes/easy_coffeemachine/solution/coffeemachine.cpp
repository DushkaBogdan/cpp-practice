#include "coffeemachine.hpp"

/*****************************************************************************/
const int CoffeeMachine::waterRecipes[2] = { 120, 200 };
const int CoffeeMachine::beansStrength[3] = { 4, 8, 12 };

CoffeeMachine::CoffeeMachine(int _coffeeBeans, int _water, int _coffeePortions)
	: m_maxWaterLiters(_water)
	, m_maxCoffeeBeans(_coffeeBeans)
	, m_maxCoffeePortions(_coffeePortions)
	, m_nActualWaterLeft(0)
	, m_nActualCoffeBeansLeft(0)
	, m_nActualCoffeePortionsLeft(_coffeePortions)
{
	if (!isValid())
		throw "Incorrect initial parameters";
}

bool CoffeeMachine::isValid() const
{
	if (   m_maxWaterLiters <= 0
		|| m_maxCoffeeBeans <= 0
		|| m_maxCoffeePortions <= 0
		)
		return false;
	else
		return true;
}

int CoffeeMachine::loadBeans()
{
	int beansStored = m_maxCoffeeBeans - m_nActualCoffeBeansLeft;
	m_nActualCoffeBeansLeft = m_maxCoffeeBeans;

	return beansStored;
}

int CoffeeMachine::loadWater()
{	
	int waterStored = m_maxWaterLiters - m_nActualWaterLeft;
	m_nActualWaterLeft = m_maxWaterLiters;

	return waterStored;
}
void CoffeeMachine::cleanWaste()
{
	m_nActualCoffeePortionsLeft = m_maxCoffeePortions;
}

bool CoffeeMachine::makeCoffee(Recipe _res, Strength _str)
{
	if (m_nActualCoffeePortionsLeft == 0
		|| m_nActualWaterLeft < waterRecipes[_res]
		|| m_nActualCoffeBeansLeft < beansStrength[_str])
		return false;
	
	m_nActualWaterLeft -= waterRecipes[_res];
	m_nActualCoffeBeansLeft -= beansStrength[_str];
	--m_nActualCoffeePortionsLeft;

	return true;
	
}

void CoffeeMachine::washMachine()
{
	if (m_nActualWaterLeft < CoffeeMachine::WATER_FOR_WASHING)
		m_nActualWaterLeft = 0;
	else
		m_nActualWaterLeft -= CoffeeMachine::WATER_FOR_WASHING;
}

CoffeeMachine::operator bool() const
{
	return (m_nActualWaterLeft >= CoffeeMachine::WATER_FOR_AMERICANO
		 && m_nActualCoffeBeansLeft >= CoffeeMachine::BEANS_FOR_STRONG);
}

/*****************************************************************************/
