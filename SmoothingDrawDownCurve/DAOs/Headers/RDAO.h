#pragma once

#include <fstream>
#include "../Utilities/Parser.h"
#include "../Utilities/PathsHandler.h"
#include "../../Domain/Models/Structures/R.h"

bool saveR(Account* theAccount, R* r, std::filesystem::path& filePath);

std::list<R*> getRs(Account* theAccount, std::filesystem::path& filePath);
std::list<R*> getNRs(Account* theAccount, size_t startingIndex, size_t endingIndex, std::filesystem::path& filePath);
bool deleteAccountRs(Account* theAccount, std::filesystem::path& filePath);
int getRsCreatedNumber(Account* theAccount, std::filesystem::path& filePath);
bool increaseRsCreatedNumber(Account* theAccount, std::filesystem::path& filePath);