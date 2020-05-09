#include "TournamentTable.hpp"
#include "Match.hpp"
#include "FootballClub.hpp"

#include <algorithm>
#include <functional>

TournamentTable::TournamentTable()
{}

void TournamentTable::FootBallClubInfo::printInfo(std::ostream &_o) const
{
		_o << "Name: " << m_sName
			<< " Points: " << m_nPoints << ' '
			<< " Wins: " << m_nWins << ' '
			<< " Draws: " << m_nDraws << ' '
			<< " Looses: " << m_nLooses << ' '
			<< " Goals Scored: " << m_nGoalsScored << ' '
			<< " Goals Conceded: " << m_nGoalsConceded << '\n';
}


TournamentTable::~TournamentTable()
{
	if (!this->isEmpty())
		this->cleanTable();
}

bool TournamentTable::isEmpty() const
{
	return m_FC_Info_Sequence.empty();
}

void TournamentTable::cleanTable()
{
	int seqSize = m_FC_Info_Sequence.size();
	for (int i = 0; i < seqSize; i++)
		delete m_FC_Info_Sequence[i];
}

void TournamentTable::infoInsert(std::string &_sName,
	int _nPoints,
	int _nWins,
	int _nDraws,
	int _nLooses,
	int _nGoalsScored,
	int _nGoalsConceded)
{

	int seqSize = m_FC_Info_Sequence.size();
	for (int i = 0; i < seqSize; i++)
		if (m_FC_Info_Sequence[i]->m_sName == _sName)
		{
			m_FC_Info_Sequence[i]->m_nPoints += _nPoints;
			m_FC_Info_Sequence[i]->m_nWins += _nWins;
			m_FC_Info_Sequence[i]->m_nDraws += _nDraws;
			m_FC_Info_Sequence[i]->m_nLooses += _nLooses;
			m_FC_Info_Sequence[i]->m_nGoalsScored += _nGoalsScored;
			m_FC_Info_Sequence[i]->m_nGoalsConceded += _nGoalsConceded;

			return;
		}

	m_FC_Info_Sequence.push_back(new FootBallClubInfo(

		_sName,
		_nPoints,
		_nWins,
		_nDraws,
		_nLooses,
		_nGoalsScored,
		_nGoalsConceded
		));

}

void TournamentTable::addMatch(const Match &_m)
{
	std::string hostsName = _m.getHostFootballCLub().getName();
	std::string guestsName = _m.getGuestFootballCLub().getName();

	int goalsInMatchHost = _m.getFinalScoreHost();
	int goalsInMatchGuest = _m.getFinalScoreGuest();

	int HostPoints = 0;
	int HostWins = 0;
	int HostDraws = 0;
	int HostLooses = 1;

	int GuestPoints = 3;
	int GuestWins = 1;
	int GuestDraws = 0;
	int GuestLooses = 0;

	if (goalsInMatchHost > goalsInMatchGuest)
	{
		HostPoints = 3;
		HostWins = 1;
		HostDraws = 0;
		HostLooses = 0;

		GuestPoints = 0;
		GuestWins = 0;
		GuestDraws = 0;
		GuestLooses = 1;
	}
	else if (goalsInMatchHost == goalsInMatchGuest)
	{
		HostPoints = 1;
		HostWins = 0;
		HostDraws = 1;
		HostLooses = 0;

		GuestPoints = 1;
		GuestWins = 0;
		GuestDraws = 1;
		GuestLooses = 0;
	}

	infoInsert(hostsName,
		HostPoints,
		HostWins,
		HostDraws,
		HostLooses,
		goalsInMatchHost,
		goalsInMatchGuest);

	infoInsert(guestsName,
		GuestPoints,
		GuestWins,
		GuestDraws,
		GuestLooses,
		goalsInMatchGuest,
		goalsInMatchHost);

	std::sort(
		m_FC_Info_Sequence.begin(), m_FC_Info_Sequence.end(),
		std::bind(
		std::greater<int>(),
		std::bind(&FootBallClubInfo::getPoints, std::placeholders::_1),
		std::bind(&FootBallClubInfo::getPoints, std::placeholders::_2)
		)
	);

}

void TournamentTable::printTable(std::ostream &_o) const
{
	int size = m_FC_Info_Sequence.size();

	if (size != 0)
		_o << "\nTournament Table: \n";

	for (int i = 0; i < size; i++)
		m_FC_Info_Sequence[i]->printInfo(_o);

}

std::string TournamentTable::getNameOfClubAtPlace(int _place) const
{
	return m_FC_Info_Sequence[_place]->m_sName;
}