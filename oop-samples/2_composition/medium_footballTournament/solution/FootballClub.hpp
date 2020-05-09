#ifndef _FOOTBALL_CLUB_HPP_
#define _FOOTBALL_CLUB_HPP_

#include <string>


class FootballClub
{
/*----------------------------------------------------------*/

public:

/*----------------------------------------------------------*/

	FootballClub
		(
		const std::string &_sName,
		const std::string &_sTown,
		int _nYear,
		int	_nRating
		);

	std::string getName() const;
	std::string getTown() const;
	int getYear() const;
	int getRating() const;

/*----------------------------------------------------------*/

private:

/*----------------------------------------------------------*/

	FootballClub(const FootballClub&);
	FootballClub & operator = (const FootballClub &);

/*----------------------------------------------------------*/

	const std::string m_sName;

	const std::string m_sTown;

	const int m_nYear;

	int m_nRating;

/*----------------------------------------------------------*/
};

inline std::string FootballClub::getName() const
{
	return m_sName;
}
inline std::string FootballClub::getTown() const
{
	return m_sTown;
}
inline int FootballClub::getYear() const
{
	return m_nYear;
}
inline int FootballClub::getRating() const
{
	return m_nRating;
}

#endif //_FOOTBALL_CLUB_HPP_

