#pragma once
#include "AccountDataToAdd.h"
#include <cstring>
#include <list>
class Account
{
private:
	int m_Index;
	char m_Name[20];
	std::list<int> m_Rs;
	std::list<int> m_Equities;
	std::list<float> m_MovingAverage;

	void _addEquity(int newR);
	void _addAverage(float average);
public:
	Account();
	Account(int index,char* name) : m_Index(index) {
		strcat(m_Name, name);
	}
	inline const int Id() const { return m_Index; }
	inline const char* Name() const { return m_Name;}
	inline const std::list<int>& GetRsList() const { return m_Rs; }
	inline const std::list<int>& GetEquitiesList() const { return m_Equities; }
	inline const std::list<float>& GetMovingAverage() const { return m_MovingAverage; }

	void AddData(AccountDataToAdd& theDataToAdd);
};

