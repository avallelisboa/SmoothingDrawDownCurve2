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
	int newEquity = 0;
	if (values.size() > 0) {
		int lastEquity = values.back()->equity;
		newEquity = lastEquity + r->value;
	}
	else newEquity = r->value;
	return newEquity;
}

CreateAccountResult makeAccountBL(std::filesystem::path& filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
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
void _updateIndex(std::list<Account*>& accountCollection) {
	size_t count = 0;
	auto it = accountCollection.begin();
	auto endIt = accountCollection.end();
	while (it != endIt) {
		(*it)->SetId(count);
		it++;
		count++;
	}
}
DeleteAccountResult deleteAccountBL(std::filesystem::path& filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count)
{
	DeleteAccountResult result;
	try {
		accountCollection.remove(theAccount);
		_updateIndex(accountCollection);
		bool wasUpdated = updateAccountList(accountCollection, filePath);
		if (wasUpdated) {
			bool wasDecresed = decreaseAccountsCreatedNumber(filePath);
			if (wasDecresed) {
				bool wasAccountDataDeleted = deleteAccountRs(theAccount, filePath) &&
											deleteAccountEquities(theAccount, filePath) &&
											deleteAccountAverages(theAccount, filePath);
				if (wasAccountDataDeleted) {
					result.wasDeleted = true;
					result.errorMessage = "The account was deleted correctly";
				}
				else {
					result.wasDeleted = false;
					result.errorMessage = "The data of the deleted account could not be deleted";
				}
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

GetAccountsResult getAccountsBL(std::filesystem::path& filePath)
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

AddRResult addRBL(std::filesystem::path& filePath, Account* theAccount, R* theRToAdd)
{
	AddRResult result;
	Equity* aEquity = new Equity();
	Average* aAverage = new Average();
	try {
		theRToAdd->index = getRsCreatedNumber(theAccount, filePath);
		theAccount->AddR(theRToAdd);

		auto eqsList = theAccount->GetEquitiesList();
		aEquity->equity = calculateEquity(eqsList, theRToAdd);
		aEquity->index = getEquitiesCreatedNumber(theAccount, filePath);
		theAccount->AddEquity(aEquity);

		eqsList = theAccount->GetEquitiesList();
		float average = calculateAverage(eqsList, 14);	
		aAverage->average = average;
		aAverage->index = getAveragesCreatedNumber(theAccount, filePath);
		theAccount->AddAverage(aAverage);

		saveR(theAccount, theRToAdd, filePath);
		increaseRsCreatedNumber(theAccount, filePath);
		saveEquity(theAccount, aEquity, filePath);
		increaseEquityCreatedNumber(theAccount, filePath);
		saveAverage(theAccount, aAverage, filePath);
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

size_t getAccountsCountBL(std::filesystem::path& filePath)
{
	return getAccountsCreatedNumber(filePath);
}

UpdateAccountResult updateAccountBL(std::filesystem::path& filePath, Account* theAccount, std::list<Account*>& accountCollection)
{
	UpdateAccountResult result;
	auto it = accountCollection.begin();
	while (it != accountCollection.end()) {
		if ((*it)->Id() == theAccount->Id()) {
			(*it)->SetName(theAccount->Name());
			break;
		}
		it++;
	}
	try {		
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