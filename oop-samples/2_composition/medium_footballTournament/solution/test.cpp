#include "Application.hpp"

#include "vld.h"

#include <iostream>

int main()
{
	try
	{
		Application app;

		app.runTournament();

		app.printAllMatchesResults(std::cout);

		app.printTournamentResult(std::cout);

		app.printWinnerClubName(std::cout);

		app.printTwoLoosersName(std::cout);
	}
	catch (const char *_s)
	{
		std::cerr << _s << std::endl;
		return -1;
	}

	return 0;
}