#include "Admin.h"

Admin Admin::s_Instance;

void Admin::Init() {
	_loadData();
}
void Admin::_loadData() {
	m_Accounts = getAccountsBL();
}
void Admin::OpenAccount(Account* theAccount) {
	m_OpenAccounts.push_back(theAccount);
}
void Admin::MakeAccount(char name[20]) {
	Account* aAccount = new Account(m_AccountsCount, name);
	makeAccountBL(aAccount, m_Accounts, m_AccountsCount);
}
void Admin::UpateAccount(Account* account)
{
	updateAccount(account);
}
void Admin::DeleteAccount(Account* account)
{
	deleteAccountBL(account, m_Accounts, m_AccountsCount);
}
void Admin::ExitAccount(Account* account) {
	m_OpenAccounts.remove(account);
}

bool Admin::SaveData()
{
	return false;
}

Admin::~Admin()
{
	auto it = m_Accounts.begin();
	while (it != m_Accounts.end()) {
		delete (*it);
	}
}