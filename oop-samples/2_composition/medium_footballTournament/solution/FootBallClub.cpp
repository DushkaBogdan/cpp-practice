#include "FootballClub.hpp"

FootballClub::FootballClub
(
const std::string &_sName,
const std::string &_sTown,
int _nYear,
int	_nRating
)
:m_sName(_sName), m_sTown(_sTown), m_nYear(_nYear), m_nRating(_nRating)
{
	if (m_sName.empty())
		throw "Name of Club can't be empty!";
	if (m_sTown.empty())
		throw "Name of Club's Town can't be empty!";
	if (m_nYear > 2020)
		throw "Club of the future?";
	if (m_nRating < 1 || m_nRating > 5)
		throw "Club rating should be from 1 to 5!";

}