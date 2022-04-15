#include "Account.h"

void Account::AddData(AccountDataToAdd& theDataToAdd)
{
	m_Rs.push_back(theDataToAdd.R);
	_addEquity(theDataToAdd.Equity);
	_addAverage(theDataToAdd.Average);
}

void Account::_addEquity(int newR)
{
	int equity =m_Equities.back() + newR;
	m_Equities.push_back(equity);
}

void Account::_addAverage(float average)
{
	m_MovingAverage.push_back(average);
}
