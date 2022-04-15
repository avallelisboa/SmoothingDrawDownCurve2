#include "AccountBL.h"


float calculateAverage(std::list<int>& values, size_t periodsNumber)
{
	if(values.size() == 0 || values.size() < periodsNumber)
		return 0.0f;
	
	int sum = 0;
	std::list<int>::iterator it = values.end();
	it--;
	for (size_t count = 0; count < periodsNumber; count++) {
		sum += *it;
		if(count < periodsNumber -1)
			it--;
	}
	float average = (float)sum / periodsNumber;
	return average;
}

bool isGhostMode(int lastEquity, float lastAverage)
{
	return lastEquity < lastAverage;
}

void makeAccountBL(Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
{
	accountCollection.push_back(theAccount);
	count++;
}

void deleteAccountBL(Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
{
	accountCollection.remove(theAccount);
	count--;
}

std::list<Account*>& getAccountsBL()
{
	getAccounts();
}

void addRBL(Account* theAccount, int r)
{
	AccountDataToAdd aData;
	aData.R = r;
	int acum = *(theAccount->GetEquitiesList().end()--);
	aData.Equity = acum + r;
	auto equitites = theAccount->GetEquitiesList();
	aData.Average = calculateAverage(equitites,14);

	theAccount->AddData(aData);
}
