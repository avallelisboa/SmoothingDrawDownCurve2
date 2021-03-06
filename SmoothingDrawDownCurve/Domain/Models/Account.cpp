#include "Account.h"

Account::Account()
{
}

Account::Account(int index, char* name) : m_Index(index) {
	strcat(m_Name, name);
}
void Account::SetName(const char* theName)
{
	memset(m_Name, 0, sizeof(char) * 20);
	strcat(m_Name, theName);
}

void Account::LoadData(std::list<R*>& rs, std::list<Equity*>& eqs, std::list<Average*>& ma)
{
	m_Rs = rs;
	m_Equities = eqs;
	m_MovingAverage = ma;
}
void Account::AddR(R* theR)
{
	m_Rs.push_back(theR);
}
void Account::AddEquity(Equity* theEquity)
{
	m_Equities.push_back(theEquity);
}
void Account::AddAverage(Average* theAverage)
{
	m_MovingAverage.push_back(theAverage);
}
bool Account::_isGhostMode(int lastEquity, float lastAverage)
{
	return lastEquity < lastAverage;
}
bool Account::IsGhostMode()
{
	int lastEquity = m_Equities.back()->equity;
	float lastAverage = m_MovingAverage.back()->average;
	return _isGhostMode(lastEquity, lastAverage);
}