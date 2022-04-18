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
	saveAccount(theAccount, filePath);
	increaseAccountsCreatedNumber(filePath);
	count = getAccountsCreatedNumber(filePath);
}

void deleteAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
{
	accountCollection.remove(theAccount);
	updateAccountList(accountCollection, filePath);
	decreaseAccountsCreatedNumber(filePath);
	count = getAccountsCreatedNumber(filePath);
}

std::list<Account*> getAccountsBL(const char* filePath)
{
	std::list<Account*> accounts = getAccounts(filePath);
	auto it = accounts.begin();
	while (it != accounts.end()) {
		auto rs = getRs(*it, filePath);
		auto eqs = getEquities(*it, filePath);
		auto ma = getMovingAverage(*it, filePath);
		(*it)->LoadData(rs, eqs, ma);
	}

	return accounts;
}

void addRBL(const char* filePath, Account* theAccount, AccountDataToAdd& theData)
{
	auto eqsList = theAccount->GetEquitiesList();
	int equity = _calculateEquity(eqsList, theData.r);
	float average = calculateAverage(eqsList, 14);
	theData.r->index = getRsCreatedNumber(theAccount, filePath);
	theData.equity->equity = equity;
	theData.equity->index = getEquitiesCreatedNumber(theAccount, filePath);
	theData.average->average = average;
	theData.average->index = getAveragesCreatedNumber(theAccount, filePath);
	theAccount->AddData(theData);

	saveR(theAccount, theData.r, filePath);
	increaseRsCreatedNumber(theAccount, filePath);
	saveEquity(theAccount, theData.equity, filePath);
	increaseEquityCreatedNumber(theAccount, filePath);
	saveAverage(theAccount, theData.average, filePath);
	increaseAverageCreatedNumber(theAccount, filePath);
}

size_t getAccountsCountBL(const char* filePath)
{
	return getAccountsCreatedNumber(filePath);
}

void updateAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection)
{
	auto it = accountCollection.begin();
	while (it != accountCollection.end()) {
		if ((*it)->Id() == theAccount->Id()) {
			(*it)->SetName(theAccount->Name());
			break;
		}
		it++;
	}
	updateAccountList(accountCollection, filePath);
}
