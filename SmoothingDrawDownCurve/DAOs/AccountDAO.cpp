#include "AccountDAO.h"

bool saveAccount(Account* theAccount, const char* filePath)
{
	const char* fileName = "accounts.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ofstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		AccountFile af = makeAccountFile(theAccount);

		//Goes to the end
		file.seekp(0, std::ios_base::end);
		file.write((char*)&af, sizeof(AccountFile));
		file.close();
	}else return false;

	return true;
}
std::list<Account*> getAccounts(const char* filePath)
{
	std::list<Account*> accounts;

	const char* fileName = "accounts.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		while (!file.eof()) {
			AccountFile aAccountFile;
			file.read((char*)&aAccountFile, sizeof(AccountFile));

			Account* aAccount = makeAccount(&aAccountFile);
			accounts.push_back(aAccount);
		}
		file.close();
	}

	return accounts;
}

std::list<Account*> getNAccount(const char* filePath, size_t startingIndex, size_t endingIndex)
{
	std::list<Account*> accounts;

	const char* fileName = "accounts.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		size_t count = startingIndex;
		//Skips the registers we do not want to return
		file.seekg(startingIndex * sizeof(AccountFile), std::ios_base::beg);

		while (!file.eof() && count <= endingIndex) {
			AccountFile aAccountFile;
			file.read((char*)&aAccountFile, sizeof(AccountFile));

			Account* aAccount = makeAccount(&aAccountFile);
			accounts.push_back(aAccount);

			count++;
		}
		file.close();
	}

	return accounts;
}

int getAccountsCreatedNumber(const char* filePath)
{
	const char* fileName = "accountsNumber.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	int accountsNumber = 0;

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		file.read((char*)&accountsNumber, sizeof(int));
		file.close();
	}
	return accountsNumber;
}

bool increaseAccountsCreatedNumber(const char* filePath)
{
	const char* fileName = "accountsNumber.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	int Count = 0;

	std::fstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		file.read((char*)&Count, sizeof(int));
		Count++;
		file.write((char*)&Count, sizeof(int));
		file.close();
	}else return false;

	return true;
}

bool updateAccount(Account* theAccount, const char* filePath)
{
	return false;
}
