#pragma once

#include "../Domain/Models/Account.h"
#include "../Domain/Models/Structures/AccountDataToAdd.h"
#include "../Domain/Models/ValidationModels/CreateAccountResult.h"
#include "../Domain/Models/ValidationModels/UpdateAccountResult.h"
#include "../Domain/Models/ValidationModels/DeleteAccountResult.h"
#include "../DAOs/AccountDAO.h"
#include "../DAOs/RDAO.h"
#include "../DAOs/EquityDAO.h"
#include "../DAOs/AverageDAO.h"

#include <list>
#include <exception>

float calculateAverage(std::list<Equity*>& values, size_t periodsNumber);
bool isGhostMode(int lastEquity, float lastAverage);
CreateAccountResult makeAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count);
void addRBL(const char* filePath, Account* theAccount, AccountDataToAdd& theData);
size_t getAccountsCountBL(const char* filePath);
UpdateAccountResult updateAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection);
DeleteAccountResult deleteAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count);
std::list<Account*> getAccountsBL(const char* filePath);