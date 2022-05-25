#pragma once

#include "../../Domain/Models/Account.h"
#include "../FileObjects/AccountFile.h"
#include "../FileObjects/AverageFile.h"
#include "../FileObjects/EquityFile.h"
#include "../FileObjects/RFile.h"
#include "../Utilities/Parser.h"
#include "../Utilities/PathsHandler.h"
#include <filesystem>
#include <fstream>
#include <cstring>


bool saveAccount(Account* theAccount, std::filesystem::path& filePath);
bool updateAccountList(std::list<Account*>& theAccountList, std::filesystem::path& filePath);
std::list<Account*> getAccounts(std::filesystem::path& filePath);
int getAccountsCreatedNumber(std::filesystem::path& filePath);
bool increaseAccountsCreatedNumber(std::filesystem::path& filePath);
bool decreaseAccountsCreatedNumber(std::filesystem::path& filePath);