#pragma once

#include "../../Domain/Models/Account.h"
#include "../FileObjects/AccountFile.h"
#include "../FileObjects/AverageFile.h"
#include "../FileObjects/EquityFile.h"
#include "../FileObjects/RFile.h"

AccountFile makeAccountFile(Account* theAccount);
RFile makeRFile(int accountIndex, int index, int r);
EquityFile makeEquityFile(int accountIndex, int index, int equity);
AverageFile makeAverageFile(int accountIndex, int index, float average);
Account* makeAccount(AccountFile* theAccountFile);
R* makeR(RFile* theRFile);
Equity* makeEquity(EquityFile* theEquityFile);
Average* makeAverage(AverageFile* theAverageFile);