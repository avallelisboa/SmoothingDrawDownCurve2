#include "Account.h"

Account::Account(int index, char* name) : m_Index(index) {
	strcat(m_Name, name);
}
void Account::AddData(AccountDataToAdd& theDataToAdd)
{
	m_Rs.push_back(theDataToAdd.r);
	m_Equities.push_back(theDataToAdd.equity);
	m_MovingAverage.push_back(theDataToAdd.average);
}