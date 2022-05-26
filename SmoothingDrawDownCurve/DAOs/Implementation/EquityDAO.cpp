#include "../Headers/EquityDAO.h"

bool saveEquity(Account* theAccount, Equity* eq, std::filesystem::path& filePath){
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_equities.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::out | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		int index = eq->index;
		int equity = eq->equity;
		EquityFile aEquityFile = makeEquityFile(index, equity);

		file.seekp(0, std::ios_base::end);
		file.write((char*)&aEquityFile, sizeof(EquityFile));
		file.close();
	}
	else return false;

	return true;
}
std::list<Equity*> getEquities(Account* theAccount, std::filesystem::path& filePath) {
	std::list<Equity*> equities;

	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_equities.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		EquityFile aEquityFile;
		while (file.read((char*)&aEquityFile, sizeof(EquityFile))) {
			Equity* aEquity = makeEquity(&aEquityFile);
			equities.push_back(aEquity);
		}
		file.close();
	}

	return equities;
}
std::list<Equity*> getNEquities(Account* theAccount, size_t startingIndex, size_t endingIndex, std::filesystem::path& filePath) {
	std::list<Equity*> equities;

	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_equities.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		size_t count = startingIndex;
		//Skips the registers we do not want to return
		file.seekg(startingIndex * sizeof(EquityFile), std::ios_base::beg);

		EquityFile aEquityFile;
		while (file.read((char*)&aEquityFile, sizeof(EquityFile)) && count <= endingIndex) {
			Equity* aEquity = makeEquity(&aEquityFile);
			equities.push_back(aEquity);

			count++;
		}
		file.close();
	}

	return equities;
}
bool deleteAccountEquities(Account* theAccount, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_equities.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	return std::filesystem::remove(fullName);
}
int getEquitiesCreatedNumber(Account* theAccount, std::filesystem::path& filePath) {
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_equitiesNumber.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	int equitiesNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		file.read((char*)&equitiesNumber, sizeof(int));
		file.close();
	}else return -1;

	return equitiesNumber;
}
bool increaseEquityCreatedNumber(Account* theAccount, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_equitiesNumber.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	size_t equitiesCreatedNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::binary | std::ios::in);
	file.read((char*)&equitiesCreatedNumber, sizeof(size_t));
	equitiesCreatedNumber++;
	file.close();

	file.open(fullName, std::ios::binary | std::ios::out);
	file.clear();
	file.write((char*)&equitiesCreatedNumber, sizeof(size_t));
	file.close();

	return true;
}