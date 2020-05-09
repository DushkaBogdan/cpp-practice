#ifndef _TOURNAMENT_HPP_
#define _TOURNAMENT_HPP_


#include <string>
#include <vector>
#include <iostream>

#include "TournamentTable.hpp"

class FootballClub;
class Match;


class Tournament
{
/*----------------------------------------------------------*/

public:

/*----------------------------------------------------------*/

	Tournament(const std::string &_name, int _count);
	~Tournament();

	void AddClub(FootballClub *_pClub);

	void generateMatches();
	void printTournamentTable(std::ostream &_o) const;

	void printMatchesResults(std::ostream &_o) const;

	std::string getName() const;
	int getCountOfClubs() const;

	std::string getNameAtPlace(int _place) const;

/*----------------------------------------------------------*/

private:

/*----------------------------------------------------------*/

	Tournament(const Tournament &);
	Tournament & operator = (const Tournament &);

/*----------------------------------------------------------*/

private:

/*----------------------------------------------------------*/

	const std::string m_sName;

	const int m_nCountOfClubs;
	int m_nUsed;
	FootballClub **m_pClubsSeq;

	std::vector<Match*> m_vMatches;

	TournamentTable m_table;

};

inline std::string 
Tournament::getName() const { return m_sName; };

inline int 
Tournament::getCountOfClubs() const { return m_nCountOfClubs; };

#endif //_TOURNAMENT_HPP_