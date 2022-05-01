#include "Admin.h"

Admin Admin::s_Instance;


bool Admin::LoadData() {
	GetAccountsResult result = getAccountsBL(m_FilePath);
	if (result.wasReadFromFile) {
		m_Accounts = result.accounts;
		m_AccountsCount = getAccountsCountBL(m_FilePath);

		return true;
	}
	else {
		return false;
	}
}
AddRResult Admin::AddR(Account* theAccount, int r)
{
	AccountDataToAdd theDataToAdd;
	theDataToAdd.r = new R();
	theDataToAdd.r->value = r;
	theDataToAdd.equity = new Equity();
	theDataToAdd.average = new Average();

	AddRResult result = addRBL(m_FilePath, theAccount, theDataToAdd);

	return result;
}
CreateAccountResult Admin::MakeAccount(char name[20]) {
	Account* aAccount = new Account(m_AccountsCount, name);
	return makeAccountBL(m_FilePath, aAccount, m_Accounts, m_AccountsCount);
}
UpdateAccountResult Admin::UpdateAccount(Account* theAccount, const char* filePath)
{
	return updateAccountBL(filePath, theAccount, m_Accounts);
}
DeleteAccountResult Admin::DeleteAccount(Account* account)
{
	return deleteAccountBL(m_FilePath, account, m_Accounts, m_AccountsCount);
}
Admin::~Admin()
{
	_cleanUp();
}

void Admin::_cleanUp()
{
	_cleanUpAccounts();	
}

void Admin::_cleanUpAccounts()
{
	auto it = m_Accounts.begin();
	while (it != m_Accounts.end()) {
		_cleanRs(*it);
		_cleanEquities(*it);
		_cleanAverages(*it);
		delete(*it);
		it++;
	}
}

void Admin::_cleanRs(Account* theAccount)
{
	auto rit = theAccount->GetRsList().begin();
	auto endit = theAccount->GetRsList().end();
	while (rit != endit) {
		delete (*rit);
		rit++;
	}
}

void Admin::_cleanEquities(Account* theAccount)
{
	auto eit = theAccount->GetEquitiesList().begin();
	auto endit = theAccount->GetEquitiesList().end();
	while (eit != endit) {
		delete(*eit);
		eit++;
	}
}

void Admin::_cleanAverages(Account* theAccount)
{
	auto mit = theAccount->GetMovingAverage().begin();
	auto endit = theAccount->GetMovingAverage().end();
	while (mit != endit) {
		delete(*mit);
		mit++;
	}
}
