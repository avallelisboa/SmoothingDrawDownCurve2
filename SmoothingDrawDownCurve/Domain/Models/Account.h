#pragma once
#pragma warning(suppress : 4996)

#include <cstring>
#include <list>
#include "Structures/AccountDataToAdd.h"
#include "Structures/Average.h"
#include "Structures/Equity.h"
#include "Structures/R.h"

class Account
{
private:
	int m_Index;
	char m_Name[20];
	std::list<R*> m_Rs;
	std::list<Equity*> m_Equities;
	std::list<Average*> m_MovingAverage;
	bool _isGhostMode(int lastEquity, float lastAverage);
public:
	Account();
	Account(int index, char* name);
	inline const int Id() const { return m_Index; }
	inline const char* Name() const { return m_Name;}
	void SetName(const char* theName);
	void LoadData(std::list<R*>& rs, std::list<Equity*>& eqs, std::list<Average*>& ma);
	inline const std::list<R*>& GetRsList() const { return m_Rs; }
	inline const std::list<Equity*>& GetEquitiesList() const { return m_Equities; }
	inline const std::list<Average*>& GetMovingAverage() const { return m_MovingAverage; }

	inline bool IsThereEnoughData() { return m_Equities.size() >= 14; }

	void AddData(AccountDataToAdd& theDataToAdd);
	bool IsGhostMode();
};