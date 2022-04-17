#include "Parser.h"

AccountFile makeAccountFile(Account* theAccount) {
	AccountFile aAccountFile;
	aAccountFile.index = theAccount->Id();
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
Account* makeAccount(AccountFile* theAccountFile) {
	Account* aAccount = new Account(theAccountFile->index, theAccountFile->name);
	return aAccount;
}
R* makeR(RFile* theRFile) {
	R* aR = new R();
	aR->index = theRFile->index;
	aR->value = theRFile->value;

	return aR;
}
Equity* makeEquity(EquityFile* theEquityFile) {
	Equity* aEquity = new Equity();
	aEquity->index = theEquityFile->index;
	aEquity->equity = theEquityFile->value;

	return aEquity;
}
Average* makeAverage(AverageFile* theAverageFile) {
	Average* aAverage = new Average();
	aAverage->index = theAverageFile->index;
	aAverage->average = theAverageFile->value;

	return aAverage;
}