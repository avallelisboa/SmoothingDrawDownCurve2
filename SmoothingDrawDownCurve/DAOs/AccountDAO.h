#pragma once

#include "../Domain/Models/Account.h"
#include "FileObjects/AccountFile.h"
#include "FileObjects/AverageFile.h"
#include "FileObjects/EquityFile.h"
#include "FileObjects/RFile.h"
#include "Parsing/Parser.h"
#include <fstream>
#include <cstring>

bool saveAccount(Account* theAccount, const char* filePath);
std::list<Account*> getAccounts(const char* filePath);
std::list<Account*> getNAccount(const char* filePath, size_t startingIndex, size_t endingIndex);
int getAccountsCreatedNumber(const char* filePath);
bool increaseAccountsCreatedNumber(const char* filePath);
bool updateAccount(Account* theAccount, const char* filePath);