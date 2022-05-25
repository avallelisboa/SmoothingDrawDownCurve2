#pragma once

#include <fstream>
#include "../Utilities/Parser.h"
#include "../Utilities/PathsHandler.h"
#include "../../Domain/Models/Structures/Equity.h"

bool saveEquity(Account* theAccount, Equity* eq, std::filesystem::path& filePath);
std::list<Equity*> getEquities(Account* theAccount, std::filesystem::path& filePath);
std::list<Equity*> getNEquities(Account* theAccount, size_t startingIndex, size_t endingIndex, std::filesystem::path& filePath);
bool deleteAccountEquities(Account* theAccount, std::filesystem::path& filePath);
int getEquitiesCreatedNumber(Account* theAccount, std::filesystem::path& filePath);
bool increaseEquityCreatedNumber(Account* theAccount, std::filesystem::path& filePath);