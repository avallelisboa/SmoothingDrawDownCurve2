#pragma once
#include "../Domain/Models/Account.h"
#include "FileObjects/AccountFile.h"
#include "../DAOs/Parsing/Parser.h"
#include <vector>
#include <fstream>
#include <cstring>

bool saveAccounts(std::list<Account*> accountsList);
std::list<Account*> getAccounts();
std::list<Account*> getNAccount(size_t startingIndex, size_t endingIndex);
int getAccountsCreatedNumber();