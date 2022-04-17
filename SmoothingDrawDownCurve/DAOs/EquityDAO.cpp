#include"EquityDAO.h"

bool saveEquity(Account* theAccount, Equity* eq, const char* filePath){
	const char* accountName = theAccount->Name();
	const char* fileName = "_equities.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName) + sizeof(fileName));
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
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
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
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
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
	char* fullName = (char*)alloca(sizeof(filePath)+sizeof(accountName) + sizeof(fileName));
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
bool saveEquitiesCreatedNumber(Account* theAccount, size_t theEquitiesNumber, const char* filePath) {
	const char* accountName = theAccount->Name();
	const char* fileName = "_equitiesNumber.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ofstream file;
	file.open(fullName, std::ios::binary);
	if (file.is_open()) {
		file.clear();
		file.write((char*)&theEquitiesNumber, sizeof(size_t));
		file.close();
	}else return false;

	return true;
}