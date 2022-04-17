#pragma once

#include <fstream>
#include "Parsing/Parser.h"
#include "../Domain/Models/Structures/Equity.h"

bool saveEquity(Account* theAccount, Equity* eq, const char* filePath);
std::list<Equity*> getEquities(Account* theAccount, const char* filePath);
std::list<Equity*> getNEquities(Account* theAccount, size_t startingIndex, size_t endingIndex, const char* filePath);
int getEquitiesCreatedNumber(Account* theAccount, const char* filePath);