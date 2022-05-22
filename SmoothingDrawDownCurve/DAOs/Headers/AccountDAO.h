#pragma once

#include "../../Domain/Models/Account.h"
#include "../FileObjects/AccountFile.h"
#include "../FileObjects/AverageFile.h"
#include "../FileObjects/EquityFile.h"
#include "../FileObjects/RFile.h"
#include "../Utilities/Parser.h"
#include <fstream>
#include <cstring>


bool saveAccount(Account* theAccount, const char* filePath);
bool updateAccountList(std::list<Account*>& theAccountList, const char* filePath);
std::list<Account*> getAccounts(const char* filePath);
int getAccountsCreatedNumber(const char* filePath);
bool increaseAccountsCreatedNumber(const char* filePath);
bool decreaseAccountsCreatedNumber(const char* filePath);