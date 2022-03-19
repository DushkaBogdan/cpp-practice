#ifndef _COFFEEMACHINE_HPP_
#define _COFFEEMACHINE_HPP_

/*****************************************************************************/


class CoffeeMachine
{

/*-----------------------------------------------------------------*/

private:

	const int m_maxWaterLiters;
	const int m_maxCoffeeBeans;
	const int m_maxCoffeePortions;

	int m_nActualWaterLeft;
	int m_nActualCoffeBeansLeft;
	int m_nActualCoffeePortionsLeft;

/*-----------------------------------------------------------------*/
	
private:
	
	bool isValid() const;

/*-----------------------------------------------------------------*/

public:

	enum Recipe { Espresso, Americano };

	enum Strength { Light, Medium, Strong };

	static const int WATER_FOR_ESPRESSO = 120, WATER_FOR_AMERICANO = 200;
	static const int WATER_FOR_WASHING = 500;
	static const int BEANS_FOR_LIGHT = 4, BEANS_FOR_MEDIUM = 8, BEANS_FOR_STRONG = 12;

	static const int waterRecipes[2];
	static const int beansStrength[3];

/*------------------------------------------------------------------*/

public:

	CoffeeMachine(int _coffeeBeans, int _water, int _coffeePortions);

	int getBeansWeight() const;
	int getWaterVolume() const;
	int getFreeWastePortions() const;

	int loadBeans();
	int loadWater();
	void cleanWaste();

	bool makeCoffee(Recipe, Strength);

	void washMachine();

	operator bool() const;

/*------------------------------------------------------------------*/

};

inline int CoffeeMachine::getBeansWeight() const
{
	return m_nActualCoffeBeansLeft;
}

inline int CoffeeMachine::getWaterVolume() const
{
	return m_nActualWaterLeft;
}

inline int CoffeeMachine::getFreeWastePortions() const
{
	return m_nActualCoffeePortionsLeft;
}

/*****************************************************************************/

#endif //  _COFFEEMACHINE_HPP_
