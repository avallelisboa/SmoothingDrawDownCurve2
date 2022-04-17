#include "AverageDAO.h"

bool saveAverage(Account* theAccount, Average* av, const char* filePath)
{
	const char* accountName = theAccount->Name();
	const char* fileName = "_averages.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(fileName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, accountName);
	strcat(fullName, fileName);

	std::ofstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		int index = av->index;
		float average = av->average;
		AverageFile aAverageFile = makeAverageFile(theAccount->Id(), index, average);

		file.seekp(0, std::ios_base::end);
		file.write((char*)&aAverageFile, sizeof(AverageFile));
		file.close();
	}
	else return false;

	return true;
}
std::list<Average*> getMovingAverage(Account* theAccount, const char* filePath)
{
	std::list<Average*> averages;

	const char* accountName = theAccount->Name();
	const char* fileName = "_averages.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		while (!file.eof()) {
			AverageFile aAverageFile;
			file.read((char*)&aAverageFile, sizeof(AverageFile));

			Average* aAverage = makeAverage(&aAverageFile);
			averages.push_back(aAverage);
		}
		file.close();
	}

	return averages;
}
std::list<Average*> getPartOfMovingAverage(Account* theAccount, size_t startingIndex, size_t endingIndex, const char* filePath)
{
	std::list<Average*> averages;

	const char* accountName = theAccount->Name();
	const char* fileName = "_averages.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		size_t count = startingIndex;
		//Skips the registers we do not want to return
		file.seekg(startingIndex * sizeof(AverageFile), std::ios_base::beg);

		while (!file.eof() && count <= endingIndex) {
			AverageFile aAverageFile;
			file.read((char*)&aAverageFile, sizeof(AverageFile));

			Average* aAverage = makeAverage(&aAverageFile);
			averages.push_back(aAverage);

			count++;
		}
		file.close();
	}

	return averages;
}
int getAveragesCreatedNumber(Account* theAccount, const char* filePath)
{
	const char* accountName = theAccount->Name();
	const char* fileName = "_averagesNumber.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, accountName);
	strcat(fullName, fileName);

	int averagesNumber = 0;

	std::ifstream file;
	file.open(fullName, std::ios::binary);

	if (file.is_open()) {
		file.read((char*)&averagesNumber, sizeof(int));
		file.close();
	}else return -1;

	return averagesNumber;
}
bool increaseAverageCreatedNumber(Account* theAccount, const char* filePath) {
	const char* accountName = theAccount->Name();
	const char* fileName = "_averagesNumber.bin";
	char* fullName = (char*)alloca(sizeof(filePath) + sizeof(accountName) + sizeof(fileName));
	strcat(fullName, filePath);
	strcat(fullName, fileName);

	size_t averagesCreatedNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::binary);
	if (file.is_open()) {
		file.read((char*)&averagesCreatedNumber, sizeof(size_t));
		averagesCreatedNumber++;
		file.clear();
		file.write((char*)&averagesCreatedNumber, sizeof(size_t));
		file.close();
	} else return false;

	return true;
}