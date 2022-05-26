#include"../Headers/RDAO.h"

bool saveR(Account* theAccount, R* r, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_rs.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::out | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		int rIndex = r->index;
		int value = r->value;
		RFile af = makeRFile(rIndex, value);

		//Goes to the end of the file
		file.seekp(0, std::ios_base::end);
		file.write((char*)&af, sizeof(RFile));
		file.close();
	}
	else return false;

	return true;
}

std::list<R*> getRs(Account* theAccount, std::filesystem::path& filePath)
{
	std::list<R*> rs;

	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_rs.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		RFile aRFile;
		while (file.read((char*)&aRFile, sizeof(RFile))) {
			R* ar = makeR(&aRFile);
			rs.push_back(ar);
		}
		file.close();
	}

	return rs;
}

std::list<R*> getNRs(Account* theAccount, size_t startingIndex, size_t endingIndex, std::filesystem::path& filePath)
{
	std::list<R*> rs;

	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_rs.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

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
bool deleteAccountRs(Account* theAccount, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_rs.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	return std::filesystem::remove(fullName);
}
int getRsCreatedNumber(Account* theAccount, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_rsNumber.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	int rsNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::in | std::ios::binary | std::ios::app);

	if (file.is_open()) {
		file.read((char*)&rsNumber, sizeof(int));
		file.close();
	}else return -1;

	return rsNumber;
}
bool increaseRsCreatedNumber(Account* theAccount, std::filesystem::path& filePath)
{
	const char* accountName = theAccount->Name();
	std::filesystem::path fileName = getFileName(accountName, "_rsNumber.bin");
	std::filesystem::path fullName = getFullName(filePath, fileName);

	size_t rsCreatedNumber = 0;

	std::fstream file;
	file.open(fullName, std::ios::binary | std::ios::in);
	file.read((char*)&rsCreatedNumber, sizeof(size_t));
	rsCreatedNumber++;
	file.close();

	file.open(fullName, std::ios::binary | std::ios::out);
	file.clear();
	file.write((char*)&rsCreatedNumber, sizeof(size_t));
	file.close();

	return true;
}