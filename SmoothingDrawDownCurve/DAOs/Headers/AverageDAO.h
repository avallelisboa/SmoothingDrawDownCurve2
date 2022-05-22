#pragma once

#include <fstream>
#include "../Utilities/Parser.h"
#include "../../Domain/Models/Structures/Average.h"


bool saveAverage(Account* theAccount, Average* av, const char* filePath);
std::list<Average*> getMovingAverage(Account* theAccount, const char* filePath);
std::list<Average*> getPartOfMovingAverage(Account* theAccount, size_t startingIndex, size_t endingIndex, const char* filePath);
int getAveragesCreatedNumber(Account* theAccount, const char* filePath);
bool increaseAverageCreatedNumber(Account* theAccount, const char* filePath);