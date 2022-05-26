#pragma once

#include "../../Domain/Models/Account.h"
#include "../FileObjects/AccountFile.h"
#include "../FileObjects/AverageFile.h"
#include "../FileObjects/EquityFile.h"
#include "../FileObjects/RFile.h"

AccountFile makeAccountFile(Account* theAccount);
RFile makeRFile(int index, int r);
EquityFile makeEquityFile(int index, int equity);
AverageFile makeAverageFile(int index, float average);
Account* makeAccount(AccountFile* theAccountFile);
R* makeR(RFile* theRFile);
Equity* makeEquity(EquityFile* theEquityFile);
Average* makeAverage(AverageFile* theAverageFile);