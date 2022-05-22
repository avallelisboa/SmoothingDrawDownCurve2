#pragma once

#include "../Domain/Models/Account.h"
#include "../Domain/Models/ValidationModels/CreateAccountResult.h"
#include "../Domain/Models/ValidationModels/AddRResult.h"
#include "../Domain/Models/ValidationModels/UpdateAccountResult.h"
#include "../Domain/Models/ValidationModels/DeleteAccountResult.h"
#include "../Domain/Models/ValidationModels/GetAccountsResult.h"
#include "../DAOs/Headers/AccountDAO.h"
#include "../DAOs/Headers/RDAO.h"
#include "../DAOs/Headers/EquityDAO.h"
#include "../DAOs/Headers/AverageDAO.h"

#include <list>
#include <exception>

float calculateAverage(std::list<Equity*>& values, size_t periodsNumber);
int calculateEquity(std::list<Equity*>& values, R* r);
CreateAccountResult makeAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count);
AddRResult addRBL(const char* filePath, Account* theAccount, R* theRToAdd);
size_t getAccountsCountBL(const char* filePath);
UpdateAccountResult updateAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection);
DeleteAccountResult deleteAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count);
GetAccountsResult getAccountsBL(const char* filePath);