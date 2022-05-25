#include "../Headers/AccountDAO.h"

bool saveAccount(Account* theAccount, std::filesystem::path& filePath)
{
	std::filesystem::path fileName = "accounts.bin";
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::out | std::ios::binary | std::ios::app);
	
	if (file.is_open()) {
		AccountFile af = makeAccountFile(theAccount);

		//Goes to the end
		file.seekp(0, std::ios_base::end);
		file.write((char*)&af, sizeof(AccountFile));
		file.close();
	}else return false;
	
	return true;
}
bool updateAccountList(std::list<Account*>& theAccountList, std::filesystem::path& filePath)
{
	std::filesystem::path fileName = "accounts.bin";
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::error_code aError;
	if (!std::filesystem::remove(fullName, aError))
		return false;

	if (theAccountList.size() > 0)
	{	
		std::ofstream file;
		file.open(fullName, std::ios::out | std::ios::binary);
		auto it = theAccountList.begin();
		while (it != theAccountList.end()) {
			AccountFile af = makeAccountFile(*it);
			file.write((char*)&af, sizeof(AccountFile));
			it++;
		}
		file.close();
	}

	return true;	
}
std::list<Account*> getAccounts(std::filesystem::path& filePath)
{
	std::list<Account*> accounts;

	std::filesystem::path fileName = "accounts.bin";
	std::filesystem::path fullName = getFullName(filePath, fileName);

	if (std::filesystem::exists(fullName)) {
		std::fstream file;
		file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

		if (file.is_open()) {
			AccountFile aAccountFile;
			file.seekg(0, std::ios::beg);
			while (file.read((char*)&aAccountFile, sizeof(AccountFile))) {
				Account* aAccount = makeAccount(&aAccountFile);
				accounts.push_back(aAccount);
			}
			file.close();
		}
	}

	return accounts;
}
int getAccountsCreatedNumber(std::filesystem::path& filePath)
{
	std::filesystem::path fileName = "accountsNumber.bin";
	std::filesystem::path fullName = getFullName(filePath, fileName);

	int accountsNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		file.read((char*)&accountsNumber, sizeof(int));
		file.close();
	}
	return accountsNumber;
}
bool increaseAccountsCreatedNumber(std::filesystem::path& filePath)
{
	std::filesystem::path fileName = "accountsNumber.bin";
	std::filesystem::path fullName = getFullName(filePath, fileName);

	int Count = 0;

	std::fstream file;
	file.open(fullName, std::ios::binary | std::ios::in);

	file.read((char*)&Count, sizeof(int));
	Count++;
	file.close();
	
	file.open(fullName, std::ios::binary | std::ios::out);
	file.clear();
	file.write((char*)&Count, sizeof(int));
	file.close();

	return true;
}

bool decreaseAccountsCreatedNumber(std::filesystem::path& filePath)
{
	std::filesystem::path fileName = "accountsNumber.bin";
	std::filesystem::path fullName = getFullName(filePath, fileName);

	int Count = 0;

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary);

	if (file.is_open()) {
		file.read((char*)&Count, sizeof(int));
		Count--;
		file.clear();
		file.close();
		file.open(fullName, std::ios::out | std::ios::binary);
		file.write((char*)&Count, sizeof(int));
		file.close();
	}
	else return false;

	return true;
}