#pragma once

#include <fstream>
#include "../Utilities/Parser.h"
#include "../Utilities/PathsHandler.h"
#include "../../Domain/Models/Structures/Average.h"


bool saveAverage(Account* theAccount, Average* av, std::filesystem::path& filePath);
std::list<Average*> getMovingAverage(Account* theAccount, std::filesystem::path& filePath);
std::list<Average*> getPartOfMovingAverage(Account* theAccount, size_t startingIndex, size_t endingIndex, std::filesystem::path& filePath);
bool deleteAccountAverages(Account* theAccount, std::filesystem::path& filePath);
int getAveragesCreatedNumber(Account* theAccount, std::filesystem::path& filePath);
bool increaseAverageCreatedNumber(Account* theAccount, std::filesystem::path& filePath);