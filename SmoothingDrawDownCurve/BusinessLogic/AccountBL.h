#pragma once
#include "../Domain/Models/Account.h"
#include "../DAOs/AccountDAO.h"
#include <list>

float calculateAverage(std::list<int>& values, size_t periodsNumber);
bool isGhostMode(int lastEquity, float lastAverage);
void makeAccountBL(Account* theAccount, std::list<Account*>& accountCollection, size_t& count);
void addRBL(Account* theAccount, int r);
void deleteAccountBL(Account* theAccount, std::list<Account*>& accountCollection, size_t& count);
std::list<Account*>& getAccountsBL();