#ifndef _MATCH_HPP_
#define _MATCH_HPP_

#include <iostream>

class FootballClub;

class Match
{
/*----------------------------------------------------------*/

public:

/*----------------------------------------------------------*/

	Match(FootballClub &_hostClub, FootballClub &_guestClub);

	void setFinallScore(std::ostream &_o, std::istream &_i); //Manual input method of finall score

	void generateRandomScore();

	int getFinalScoreHost() const;

	int getFinalScoreGuest() const;

	std::string getTownsName() const;

	FootballClub & getHostFootballCLub() const;
	FootballClub & getGuestFootballCLub() const;

	void printMatchResult(std::ostream &_o);
	
/*----------------------------------------------------------*/

private:

/*----------------------------------------------------------*/

	Match(const Match &);
	Match & operator = (const Match &);

/*----------------------------------------------------------*/

private:

/*----------------------------------------------------------*/

	FootballClub *m_pHost;
	FootballClub *m_pGuest;

	int m_finalScoreHost;
	int m_finalScoreGuest;
};

inline int Match::getFinalScoreHost() const
{
	return m_finalScoreHost;
}

inline int Match::getFinalScoreGuest() const
{
	return m_finalScoreGuest;
}

inline FootballClub & Match::getHostFootballCLub() const
{
	return *m_pHost;
}
inline FootballClub & Match::getGuestFootballCLub() const
{
	return *m_pGuest;
}

#endif // _MATCH_HPP_

