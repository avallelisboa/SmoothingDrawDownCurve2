#pragma once

#include "../Domain/Models/Account.h"
#include "../Domain/Models/Structures/AccountDataToAdd.h"
#include "../DAOs/AccountDAO.h"
#include "../DAOs/RDAO.h"
#include "../DAOs/EquityDAO.h"
#include "../DAOs/AverageDAO.h"

#include <list>

float calculateAverage(std::list<Equity*>& values, size_t periodsNumber);
bool isGhostMode(int lastEquity, float lastAverage);
void makeAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count);
void addRBL(const char* filePath, Account* theAccount, AccountDataToAdd& theData);
void updateAccountBL(const char* filePath, Account* theAccount);
void deleteAccountBL(const char* filePath, Account* theAccount, std::list<Account*>& accountCollection, size_t& count);
std::list<Account*> getAccountsBL(const char* filePath);