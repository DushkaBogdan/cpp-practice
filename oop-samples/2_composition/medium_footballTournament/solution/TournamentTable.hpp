#ifndef _TOURNAMENT_TABLE_HPP_
#define _TOURNAMENT_TABLE_HPP_

#include <iostream>
#include <map>
#include <vector>


class Match;

class TournamentTable
{
/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	struct FootBallClubInfo //Information about Club during tournament
	{
	public:

		FootBallClubInfo
			(
			std::string &_sName,
			int _nPoints,
			int _nWins,
			int _nDraws,
			int _nLooses,
			int _nGoalsScored,
			int _nGoalsConceded
			)
			:m_sName(_sName),
			m_nPoints(_nPoints),
			m_nWins(_nWins),
			m_nDraws(_nDraws),
			m_nLooses(_nLooses),
			m_nGoalsScored(_nGoalsScored),
			m_nGoalsConceded(_nGoalsConceded)
		{}

		void printInfo(std::ostream &_o) const;

		int getPoints() const { return m_nPoints; };

		const std::string m_sName;
		int m_nPoints;
		int m_nWins;
		int m_nDraws;
		int m_nLooses;
		int m_nGoalsScored;
		int m_nGoalsConceded;

	};

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	TournamentTable();

	~TournamentTable();

	bool isEmpty() const;

	void cleanTable();

	void addMatch(const Match &_m);

	void printTable(std::ostream &_o) const;

	std::string getNameOfClubAtPlace(int _place) const;


/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	TournamentTable(const TournamentTable &);
	TournamentTable & operator = (const TournamentTable &);

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::vector<FootBallClubInfo*>m_FC_Info_Sequence;

/*-----------------------------------------------------------------*/

	void infoInsert(std::string &_sName,
		int _nPoints,
		int _nWins,
		int _nDraws,
		int _nLooses,
		int _nGoalsScored,
		int _nGoalsConceded);

/*----------------------------------------------------------*/

};

#endif //_TOURNAMENT_TABLE_HPP_

