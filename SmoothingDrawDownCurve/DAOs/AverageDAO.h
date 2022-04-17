#pragma once

#include <fstream>
#include "Parsing/Parser.h"
#include "../Domain/Models/Structures/Average.h"

bool saveAverage(Account* theAccount, Average* av, const char* filePath);
std::list<Average*> getMovingAverage(Account* theAccount, const char* filePath);
std::list<Average*> getPartOfMovingAverage(Account* theAccount, size_t startingIndex, size_t endingIndex, const char* filePath);
int getAveragesCreatedNumber(Account* theAccount);
bool saveRsCreatedNumber(Account* theAccount, size_t theRsCreatedNumber, const char* filePath);
bool saveAverageCreatedNumber(Account* theAccount, size_t theAveragesNumber, const char* filePath);
bool saveEquitiesCreatedNumber(Account* theAccount, size_t theEquitiesNumber, const char* filePath);