#include "AccountBL.h"


float calculateAverage(std::list<Equity*>& values, size_t periodsNumber)
{
	if(values.size() == 0 || values.size() < periodsNumber)
		return 0.0f;
	
	int sum = 0;
	std::list<Equity*>::iterator it = values.end();
	it--;
	for (size_t count = 0; count < periodsNumber; count++) {
		sum += (*it)->equity;
		if(count < periodsNumber -1)
			it--;
	}
	float average = (float)sum / periodsNumber;
	return average;
}

int _calculateEquity(std::list<Equity*>& values, R* r)
{
	int lastEquity = (values.back()--)->equity;
	int newEquity = lastEquity + r->value;
	return newEquity;
}

bool isGhostMode(int lastEquity, float lastAverage)
{
	return lastEquity < lastAverage;
}

void makeAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
{
	accountCollection.push_back(theAccount);
	count = getAccountsCreatedNumber(filePath);
}

void deleteAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
{
	accountCollection.remove(theAccount);
	count--;
}

std::list<Account*> getAccountsBL(const char* filePath)
{
	std::list<Account*> accounts = getAccounts(filePath);
	return accounts;
}

void addRBL(const char* filePath, Account* theAccount, AccountDataToAdd& theData)
{
	auto eqsList = theAccount->GetEquitiesList();
	R* r = theData.r;
	int equity = _calculateEquity(eqsList, r);
	float average = calculateAverage(eqsList, 14);
	theData.equity->equity = equity;
	theData.average->average = average;
	theAccount->AddData(theData);

	saveR(theAccount, r, filePath);
	saveEquity(theAccount, theData.equity, filePath);
	saveAverage(theAccount, theData.average, filePath);
}

void updateAccountBL(const char* filePath, Account* theAccount)
{
	updateAccount(theAccount, filePath);
}
