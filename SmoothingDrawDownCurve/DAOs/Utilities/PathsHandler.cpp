#include "PathsHandler.h"

std::filesystem::path getFullName(std::filesystem::path& thePath, std::filesystem::path& fileName)
{
	std::filesystem::path fullName(thePath);
	fullName += fileName;
	return fullName;
}

std::filesystem::path getFileName(const char* accountName, const char* fileName)
{
	std::filesystem::path fullFileName(accountName);
	fullFileName += fileName;
	return fullFileName;
}
