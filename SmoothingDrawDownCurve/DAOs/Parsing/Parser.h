#pragma once
#include "../../Domain/Models/Account.h"
#include "../FileObjects/AccountFile.h"
#include "../FileObjects/AverageFile.h"
#include "../FileObjects/EquityFile.h"
#include "../FileObjects/RFile.h"

AccountFile makeAccountFile(Account* theAccount) {
	AccountFile aAccountFile;
	aAccountFile.index = theAccount -> Id();
	strcat(aAccountFile.name, theAccount->Name());
	
	return aAccountFile;
}
RFile makeRFile(int accountIndex, int index, int r) {
	RFile aRFile;
	aRFile.accountIndex = accountIndex;
	aRFile.index = index;
	aRFile.value = r;

	return aRFile;
}
EquityFile makeEquityFile(int accountIndex, int index, int equity) {
	EquityFile aEquityFile;
	aEquityFile.accountIndex = accountIndex;
	aEquityFile.index = index;
	aEquityFile.value = equity;

	return aEquityFile;
}
AverageFile makeAverageFile(int accountIndex, int index, float average) {
	AverageFile aAverageFile;
	aAverageFile.accountIndex = accountIndex;
	aAverageFile.index = index;
	aAverageFile.value = average;

	return aAverageFile;
}