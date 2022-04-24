#include"EquityDAO.h"

bool saveEquity(Account* theAccount, Equity* eq, const char* filePath){
	const char* accountName = theAccount->Name();
	const char* fileName = "_equities.bin";
	size_t totalsize = strlen(filePath) + strlen(fileName) + strlen(fileName) + 1;
	char* fullName = (char*)alloca(totalsize);
	memset(fullName, 0, totalsize);
	strcat(fullName, filePath);
	strcat(fullName, accountName);
	strcat(fullName, fileName);

	std::ofstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		int index = eq->index;
		int equity = eq->equity;
		EquityFile aEquityFile = makeEquityFile(theAccount->Id(), index, equity);

		file.seekp(0, std::ios_base::end);
		file.write((char*)&aEquityFile, sizeof(EquityFile));
		file.close();
	}
	else return false;

	return true;
}
std::list<Equity*> getEquities(Account* theAccount, const char* filePath) {
	std::list<Equity*> equities;

	const char* accountName = theAccount->Name();
	const char* fileName = "_equities.bin";
	size_t totalsize = strlen(filePath) + strlen(fileName) + strlen(fileName) + 1;
	char* fullName = (char*)alloca(totalsize);
	memset(fullName, 0, totalsize);
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		while (!file.eof()) {
			EquityFile aEquityFile;
			file.read((char*)&aEquityFile, sizeof(EquityFile));

			Equity* aEquity = makeEquity(&aEquityFile);
			equities.push_back(aEquity);
		}
		file.close();
	}

	return equities;
}
std::list<Equity*> getNEquities(Account* theAccount, size_t startingIndex, size_t endingIndex, const char* filePath) {
	std::list<Equity*> equities;

	const char* accountName = theAccount->Name();
	const char* fileName = "_equities.bin";
	size_t totalsize = strlen(filePath) + strlen(fileName) + strlen(fileName) + 1;
	char* fullName = (char*)alloca(totalsize);
	memset(fullName, 0, totalsize);
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		size_t count = startingIndex;
		//Skips the registers we do not want to return
		file.seekg(startingIndex * sizeof(EquityFile), std::ios_base::beg);

		while (!file.eof() && count <= endingIndex) {
			EquityFile aEquityFile;
			file.read((char*)&aEquityFile, sizeof(EquityFile));

			Equity* aEquity = makeEquity(&aEquityFile);
			equities.push_back(aEquity);

			count++;
		}
		file.close();
	}

	return equities;
}
int getEquitiesCreatedNumber(Account* theAccount, const char* filePath) {
	const char* accountName = theAccount->Name();
	const char* fileName = "_equitiesNumber.bin";
	size_t totalsize = strlen(filePath) + strlen(fileName) + strlen(fileName) + 1;
	char* fullName = (char*)alloca(totalsize);
	memset(fullName, 0, totalsize);
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	int equitiesNumber = 0;

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		file.read((char*)&equitiesNumber, sizeof(int));
		file.close();
	}else return -1;

	return equitiesNumber;
}
bool increaseEquityCreatedNumber(Account* theAccount, const char* filePath)
{
	const char* accountName = theAccount->Name();
	const char* fileName = "_equitiesNumber.bin";
	size_t totalsize = strlen(filePath) + strlen(fileName) + strlen(fileName) + 1;
	char* fullName = (char*)alloca(totalsize);
	memset(fullName, 0, totalsize);
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	size_t equitiesCreatedNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::binary);
	if (file.is_open()) {
		file.read((char*)&equitiesCreatedNumber, sizeof(size_t));
		equitiesCreatedNumber++;
		file.clear();
		file.write((char*)&equitiesCreatedNumber, sizeof(size_t));
		file.close();
	}
	else return false;

	return true;
}