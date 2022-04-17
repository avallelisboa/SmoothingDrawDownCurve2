#include "RDAO.h"

bool saveR(Account* theAccount, R* r, const char* filePath)
{
	const char* accountName = theAccount->Name();
	const char* fileName = "_rs.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, accountName);
	strcat(fullName, fileName);

	std::ofstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		int rIndex = r->index;
		int value = r->value;
		RFile af = makeRFile(theAccount->Id(), rIndex, value);

		//Goes to the end of the file
		file.seekp(0, std::ios_base::end);
		file.write((char*)&af, sizeof(RFile));
		file.close();
	}
	else return false;

	return true;
}

std::list<R*> getRs(Account* theAccount, const char* filePath)
{
	std::list<R*> rs;

	const char* accountName = theAccount->Name();
	const char* fileName = "_rs.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		while (!file.eof()) {
			RFile aRFile;
			file.read((char*)&aRFile, sizeof(RFile));

			R* ar = makeR(&aRFile);
			rs.push_back(ar);
		}
		file.close();
	}

	return rs;
}

std::list<R*> getNRs(Account* theAccount, size_t startingIndex, size_t endingIndex, const char* filePath)
{
	std::list<R*> rs;

	const char* accountName = theAccount->Name();
	const char* fileName = "_rs.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, accountName);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		size_t count = startingIndex;
		//Skips the registers we do not want to return
		file.seekg(startingIndex * sizeof(RFile), std::ios_base::beg);

		while (!file.eof() && count <= endingIndex) {
			RFile aRFile;
			file.read((char*)&aRFile, sizeof(RFile));

			R* ar = makeR(&aRFile);
			rs.push_back(ar);

			count++;
		}
		file.close();
	}

	return rs;
}
int getRsCreatedNumber(Account* theAccount, const char* filePath)
{
	const char* accountName = theAccount->Name();
	const char* fileName = "_rsNumber.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, accountName);
	strcat(fullName, fileName);

	int rsNumber = 0;

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		file.read((char*)&rsNumber, sizeof(int));
		file.close();
	}else return -1;

	return rsNumber;
}
bool increaseRsCreatedNumber(Account* theAccount, const char* filePath)
{
	const char* accountName = theAccount->Name();
	const char* fileName = "_rsNumber.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	size_t rsCreatedNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::binary);
	if (file.is_open()) {
		file.read((char*)&rsCreatedNumber, sizeof(size_t));
		rsCreatedNumber++;
		file.clear();
		file.write((char*)&rsCreatedNumber, sizeof(size_t));
		file.close();
	}
	else return false;

	return true;
}