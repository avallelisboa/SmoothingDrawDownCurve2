#include "AccountDAO.h"

bool _saveEquitieData(Account* theAccount, std::list<int>& eqs) {
	const char* filePath = "../Data/";
	const char* accountName = theAccount->Name();
	const char* fileName = "_eqs.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, accountName);
	strcat(fullName, fileName);

	std::ofstream file;
	file.open(fullName, std::ios::binary);
	
	if (file.is_open()) {
		auto it = eqs.begin();
		while (it != eqs.end()) {
			EquityFile ef = makeEquityFile(theAccount->Id(), )
		}
	}

}
bool _saveRsData(Account* theAccount, std::list<int>& rs) {
	const char* filePath = "../Data/";
	const char* accountName = theAccount->Name();
	const char* fileName = "_rs.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, accountName);
	strcat(fullName, fileName);

	std::ofstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		auto it = rs.begin();
		while (it != rs.end()) {
			int rIndex = &(*it) - &(*rs.begin());
			RFile af = makeRFile(theAccount->Id(), rIndex, *it);

			file.write((char*)&af, sizeof(RFile));
			it++;
		}
	}
}
bool _saveAccountData(Account* theAccount) {
	return false;
}
bool saveAccounts(std::list<Account*> accountsList)
{
	const char* filePath = "../Data/";
	const char* fileName = "accounts.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ofstream file;
	file.open(fullName, std::ios::binary);

	auto it = accountsList.begin();
	if (file.is_open()) {
		while (it != accountsList.end()) {
			AccountFile af = makeAccountFile(*it);
			file.write((char*)&af, sizeof(AccountFile));
			it++;
		}
	}
	else return false;

	file.close();

	return true;
}
std::list<Account*> _loadAccountsFromsFile() {
	std::list<Account*> accounts;

	const char* filePath = "../Data/";
	const char* fileName = "accounts.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		while (!file.eof()) {
			Account* aAccount = new Account();
			file.read((char*)aAccount, sizeof(Account));
			accounts.push_back(aAccount);
		}
	}

	file.close();

	return accounts;
}
std::list<Account*> getAccounts()
{
	std::list<Account*> accounts;

	
}

std::list<Account*> getNAccount(size_t startingIndex, size_t endingIndex)
{
	std::list<Account*> accounts;

	const char* filePath = "../Data/";
	const char* fileName = "accounts.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		while (!file.eof()) {
			Account* aAccount = new Account();
			file.read((char*)aAccount, sizeof(Account));
			accounts.push_back(aAccount);
		}
	}

	file.close();

	return accounts;
}

int getAccountsCreatedNumber()
{
	return 0;
}