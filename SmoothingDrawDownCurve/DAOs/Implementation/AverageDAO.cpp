#include "../Headers/AverageDAO.h"


bool saveAverage(Account* theAccount, Average* av, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName,"_averages.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::out | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		int index = av->index;
		float average = av->average;
		AverageFile aAverageFile = makeAverageFile(index, average);

		file.seekp(0, std::ios_base::end);
		file.write((char*)&aAverageFile, sizeof(AverageFile));
		file.close();
	}
	else return false;

	return true;
}
std::list<Average*> getMovingAverage(Account* theAccount, std::filesystem::path& filePath)
{
	std::list<Average*> averages;

	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_averages.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		AverageFile aAverageFile;
		while (file.read((char*)&aAverageFile, sizeof(AverageFile))) {
			Average* aAverage = makeAverage(&aAverageFile);
			averages.push_back(aAverage);
		}
		file.close();
	}

	return averages;
}
std::list<Average*> getPartOfMovingAverage(Account* theAccount, size_t startingIndex, size_t endingIndex, std::filesystem::path& filePath)
{
	std::list<Average*> averages;

	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_averages.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		size_t count = startingIndex;
		//Skips the registers we do not want to return
		file.seekg(startingIndex * sizeof(AverageFile), std::ios_base::beg);

		AverageFile aAverageFile;
		while (file.read((char*)&aAverageFile, sizeof(AverageFile)) && count <= endingIndex) {
			Average* aAverage = makeAverage(&aAverageFile);
			averages.push_back(aAverage);

			count++;
		}
		file.close();
	}

	return averages;
}
bool deleteAccountAverages(Account* theAccount, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_averages.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	return std::filesystem::remove(fullName);
}
int getAveragesCreatedNumber(Account* theAccount, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_averagesNumber.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	int averagesNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		file.read((char*)&averagesNumber, sizeof(int));
		file.close();
	}else return -1;

	return averagesNumber;
}
bool increaseAverageCreatedNumber(Account* theAccount, std::filesystem::path& filePath) {
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_averagesNumber.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	size_t averagesCreatedNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);
	file.read((char*)&averagesCreatedNumber, sizeof(size_t));
	averagesCreatedNumber++;
	file.close();

	file.open(fullName, std::ios::out | std::ios::binary | std::ios::app);
	file.clear();
	file.write((char*)&averagesCreatedNumber, sizeof(size_t));
	file.close();

	return true;
}