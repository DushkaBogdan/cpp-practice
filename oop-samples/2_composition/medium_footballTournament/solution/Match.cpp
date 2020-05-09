#include "Match.hpp"
#include "FootballClub.hpp"

#include <ctime>
#include <random>

Match::Match(FootballClub &_hostClub, FootballClub &_guestClub)
	:m_pHost(&_hostClub), m_pGuest(&_guestClub), m_finalScoreHost(0), m_finalScoreGuest(0)
{
	if (m_pHost == m_pGuest)
		throw "Match Can't be Done with The Same team!";
}

int setClubsScore(std::ostream &_o, std::istream &_i)
{
	while (true)
	{
		_o << "Input Score: ";

		int clubScore = -1;
		_i >> clubScore;

		if (_i.fail())
		{
			_i.clear();			
			_o << "Invalid input, try again" << std::endl;
		}
		else if (clubScore < 0 || clubScore > 10)
			_o << "Invalid input, Value from 0 to 10 expected, try again" << std::endl;
		else
		{
			_i.ignore(32767, '\n');
			return clubScore;
		}

		_i.ignore(32767, '\n');
	}
}

void Match::setFinallScore(std::ostream &_o, std::istream &_i)
{
	_o << "Input Finall Score Between Hosts: "
		<< m_pHost->getName() << ' '
		<< "And Guests: "
		<< m_pGuest->getName() << std::endl;

	_o << "Input Hosts " << m_pHost->getName() << " Score : ";

	m_finalScoreHost = setClubsScore(_o, _i);

	_o << "Input Guests " << m_pGuest->getName() << " Score : ";

	m_finalScoreGuest = setClubsScore(_o, _i);

	

}

int genScore(int _rating)
{
	//srand((unsigned)time(nullptr));

	int finalScore = 0;

	for (int i = 0; i < _rating; i++)
	{
		int random = std::rand() % 10;

		if (random > finalScore)
			finalScore = random;
	}

	return finalScore;

}

void Match::generateRandomScore()
{
	m_finalScoreHost = genScore(m_pHost->getRating());
	
	m_finalScoreGuest = genScore(m_pGuest->getRating());
}

std::string Match::getTownsName() const
{
	return m_pHost->getTown();
}

void Match::printMatchResult(std::ostream &_o)
{
	_o << "\nResult of Match \"" << this->getHostFootballCLub().getName() << " and " << this->getGuestFootballCLub().getName() << "\"\n";
	_o << this->getHostFootballCLub().getName() << ": " << this->getFinalScoreHost() << '\n';
	_o << this->getGuestFootballCLub().getName() << ": " << this->getFinalScoreGuest() << '\n';
}