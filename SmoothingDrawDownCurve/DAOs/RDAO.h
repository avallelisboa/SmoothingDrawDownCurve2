#pragma once

#include <fstream>
#include "Parsing/Parser.h"
#include "../Domain/Models/Structures/R.h"

bool saveR(Account* theAccount, R* r, const char* filePath);

std::list<R*> getRs(Account* theAccount, const char* filePath);
std::list<R*> getNRs(Account* theAccount, size_t startingIndex, size_t endingIndex, const char* filePath);
int getRsCreatedNumber(Account* theAccount, const char* filePath);
bool increaseRsCreatedNumber(Account* theAccount, const char* filePath);