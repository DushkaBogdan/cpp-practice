#include "Tournament.hpp"
#include "TournamentTable.hpp"
#include "FootballClub.hpp"
#include "Match.hpp"

Tournament::Tournament(const std::string &_name, int _count)
	:m_sName(_name), m_nCountOfClubs(_count), m_nUsed(0)
{
	if (m_nCountOfClubs <= 0 || ((m_nCountOfClubs % 2) != 0))
		throw "Invalid count Clubs!";

	m_pClubsSeq = new FootballClub*[m_nCountOfClubs];
	for (int i = 0; i < m_nCountOfClubs; i++)
		m_pClubsSeq[i] = nullptr;

}
Tournament::~Tournament()
{
	int countMatchs = m_vMatches.size();
	for (int i = 0; i < countMatchs; i++)
		delete m_vMatches[i];

	for (int i = 0; i < m_nCountOfClubs; i++)
		delete m_pClubsSeq[i];
	delete[]m_pClubsSeq;

	
}

void Tournament::AddClub(FootballClub *_pClub)
{
	if (_pClub == nullptr)
		throw "You can't add empty club to tournament!";
	else
		m_pClubsSeq[m_nUsed++] = _pClub;
}

void Tournament::generateMatches()
{
	for (int i = 0; i < m_nCountOfClubs; i++)
	{
		for (int j = 0; j < m_nCountOfClubs; j++)
		{
			
			if (i == j) // Footballclub can't play match with itself 
				continue;
			else
			{
				Match *pMatch = new Match(*m_pClubsSeq[i], *m_pClubsSeq[j]);
				pMatch->generateRandomScore();
				//pMatch->setFinallScore(std::cout, std::cin);
				m_vMatches.push_back(pMatch);
				m_table.addMatch(*pMatch);
			}

		}
	}
}
void Tournament::printTournamentTable(std::ostream &_o) const
{
	m_table.printTable(_o);
}

std::string Tournament::getNameAtPlace(int _place) const
{
	return m_table.getNameOfClubAtPlace(_place);
}

void Tournament::printMatchesResults(std::ostream &_o) const
{
	int countOfMatches = m_vMatches.size();
	for (int i = 0; i < countOfMatches; i++)
		m_vMatches[i]->printMatchResult(std::cout);

}