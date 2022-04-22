#include "Admin.h"

Admin Admin::s_Instance;

void Admin::Init() {
	_loadData();
}
void Admin::_loadData() {
	m_Accounts = getAccountsBL(m_FilePath);
	m_AccountsCount = getAccountsCountBL(m_FilePath);
}
void Admin::OpenAccount(Account* theAccount) {
	m_OpenAccounts.push_back(theAccount);
}
void Admin::AddR(Account* theAccount, int r)
{
	AccountDataToAdd theDataToAdd;
	theDataToAdd.r = new R();
	theDataToAdd.r->value = r;
	theDataToAdd.equity = new Equity();
	theDataToAdd.average = new Average();

	addRBL(m_FilePath, theAccount, theDataToAdd);
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
void Admin::ExitAccount(Account* account) {
	m_OpenAccounts.remove(account);
}
Admin::~Admin()
{
	_cleanUp();
}

void Admin::_cleanUp()
{
	auto it = m_Accounts.begin();
	while (it != m_Accounts.end()) {
		_cleanRs(*it);
		_cleanEquities(*it);
		_cleanAverages(*it);
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
