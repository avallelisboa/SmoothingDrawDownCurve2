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
int calculateEquity(std::list<Equity*>& values, R* r)
{
	int lastEquity = values.back()->equity;
	int newEquity = lastEquity + r->value;
	return newEquity;
}

CreateAccountResult makeAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
{
	CreateAccountResult result;
	try {
		count = getAccountsCreatedNumber(filePath);
		if (count < 10) {
			bool wasSaved = saveAccount(theAccount, filePath);
			if (wasSaved){
				bool wasIncreased = increaseAccountsCreatedNumber(filePath);
				if (wasIncreased)
					accountCollection.push_back(theAccount);
				else throw std::exception("accounts created count could not be increased");
			}
			else {
				result.wasCreated = false;
				result.errorMessage = "The account could not be saved";
			}
		}
		else {
			result.wasCreated = false;
			result.errorMessage = "You can only have ten accounts created.";
		}
	}
	catch (std::exception& ex) {
		result.wasCreated = false;
		result.errorMessage = ex.what();
	}
	return result;
}
DeleteAccountResult deleteAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
{
	DeleteAccountResult result;

	try {
		accountCollection.remove(theAccount);
		bool wasUpdated = updateAccountList(accountCollection, filePath);
		if (wasUpdated) {
			bool wasDecresed = decreaseAccountsCreatedNumber(filePath);
			if (wasDecresed) {
				result.wasDeleted = true;
				result.errorMessage = "The account was deleted correctly";
			}
			else {
				result.wasDeleted = false;
				result.errorMessage = "Accounts created number could not be decreased";
			}
		}
		else {
			result.wasDeleted = false;
			result.errorMessage = "The account could not be deleted";
		}
		count = getAccountsCreatedNumber(filePath);
	}
	catch (std::exception& ex) {
		result.wasDeleted = false;
		result.errorMessage = ex.what();
	}
	return result;
}

GetAccountsResult getAccountsBL(const char* filePath)
{
	GetAccountsResult result;

	try {
		result.accounts = getAccounts(filePath);
	
		auto it = result.accounts.begin();
		while (it != result.accounts.end()) {
			auto rs = getRs(*it, filePath);
			auto eqs = getEquities(*it, filePath);
			auto ma = getMovingAverage(*it, filePath);
			(*it)->LoadData(rs, eqs, ma);
			it++;
		}
	}
	catch (std::exception& ex) {
		result.wasReadFromFile = false;
		result.errorMessage = ex.what();
	}

	return result;
}

AddRResult addRBL(const char* filePath, Account* theAccount, AccountDataToAdd& theData)
{
	AddRResult result;

	auto eqsList = theAccount->GetEquitiesList();
	int equity = calculateEquity(eqsList, theData.r);
	float average = calculateAverage(eqsList, 14);
	try {
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

		result.wasAdded = true;
		result.errorMessage = "The add was added correctly";
	}
	catch (std::exception& ex) {
		result.wasAdded = false;
		result.errorMessage = "There was an error at trying to add the R";
	}

	return result;
}

size_t getAccountsCountBL(const char* filePath)
{
	return getAccountsCreatedNumber(filePath);
}

UpdateAccountResult updateAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection)
{
	UpdateAccountResult result;

	try {
		auto it = accountCollection.begin();
		while (it != accountCollection.end()) {
			if ((*it)->Id() == theAccount->Id()) {
				(*it)->SetName(theAccount->Name());
				break;
			}
			it++;
		}
		bool wasUpdated = updateAccountList(accountCollection, filePath);
		if (wasUpdated) {
			result.wasUpdated = true;
			result.errorMessage = "The account was updated correctly";
		}
		else {
			result.wasUpdated = false;
			result.errorMessage = "The account could not be updated";
		}
	}
	catch (std::exception& ex) {
		result.wasUpdated = false;
		result.errorMessage = "The account could not be updated";
	}	

	return result;
}