#include "Application.hpp"
#include "Tournament.hpp"
#include "FootballClub.hpp"

FootballClub* Application::createFootballClub(
	const std::string &_sName,
	const std::string &_sTown,
	int _nYear,
	int	_nRating)
{
	if (_sName.empty())
		throw "Name of Club can't be empty!";
	else if (_sTown.empty())
		throw "Name of Club's Town can't be empty!";
	else if (_nYear > 2020)
		throw "Club of the future?";
	else if (_nRating < 1 || _nRating > 5)
		throw "Club rating should be from 1 to 5!";
	else
		return new FootballClub(_sName, _sTown, _nYear, _nRating);

	return nullptr;
}

Application::Application()
{
	m_tournament = new Tournament("TournamentName", 4);

}

Application::~Application()
{
	delete m_tournament;
}

void Application::runTournament()
{

	FootballClub *m_pClub1 = createFootballClub("aname1", "town1", 1991, 2);
	FootballClub *m_pClub2 = createFootballClub("bname2", "town2", 1992, 3);
	FootballClub *m_pClub3 = createFootballClub("cname3", "town3", 1993, 1);
	FootballClub *m_pClub4 = createFootballClub("dname4", "town4", 1994, 4);

	m_tournament->AddClub(m_pClub1);
	m_tournament->AddClub(m_pClub2);
	m_tournament->AddClub(m_pClub3);
	m_tournament->AddClub(m_pClub4);

	

	m_tournament->generateMatches();
}

void Application::printAllMatchesResults(std::ostream &_o) const
{
	m_tournament->printMatchesResults(_o);
}

void Application::printTournamentResult(std::ostream &_o) const
{
	m_tournament->printTournamentTable(_o);
}

void Application::printWinnerClubName(std::ostream &_o) const
{
	_o << '\n' << "Club: " << m_tournament->getNameAtPlace(0) << " won the Tournament, Congratulations!" << '\n';
}

void Application::printTwoLoosersName(std::ostream &_o) const
{
	_o << '\n' << "Club: " <<  m_tournament->getNameAtPlace(2) << " took preLast place." << '\n';
	_o << '\n'  << "Club: " <<  m_tournament->getNameAtPlace(3) << " lost the Tournament...." << '\n';
}