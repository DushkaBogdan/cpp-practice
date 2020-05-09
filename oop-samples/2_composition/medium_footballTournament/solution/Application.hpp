#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

#include <iostream>

class FootballClub;
class Tournament;

class Application
{
/*----------------------------------------------------------*/

public:

/*----------------------------------------------------------*/

	Application();

	~Application();

	void runTournament();

	void printAllMatchesResults(std::ostream &_o) const;

	void printTournamentResult(std::ostream &_o) const;

	void printWinnerClubName(std::ostream &_o) const;

	void printTwoLoosersName(std::ostream &_o) const;

/*----------------------------------------------------------*/

private:

/*----------------------------------------------------------*/

	Application(const Application &);
	Application & operator = (const Application &);

/*----------------------------------------------------------*/

private:

/*----------------------------------------------------------*/

	FootballClub* createFootballClub(
		const std::string &_sName,
		const std::string &_sTown,
		int _nYear,
		int	_nRating);

/*----------------------------------------------------------*/

	Tournament *m_tournament;	

};

#endif //_APPLICATION_HPP_