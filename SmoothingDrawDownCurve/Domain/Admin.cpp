#include "Admin.h"

Admin Admin::s_Instance;

void Admin::Init() {
	_loadData();
}
void Admin::_loadData() {
	m_Accounts = getAccountsBL(m_FilePath);
}
void Admin::OpenAccount(Account* theAccount) {
	m_OpenAccounts.push_back(theAccount);
}
void Admin::MakeAccount(char name[20]) {
	Account* aAccount = new Account(m_AccountsCount, name);
	makeAccountBL(m_FilePath, aAccount, m_Accounts, m_AccountsCount);
}
void Admin::UpateAccount(Account* account)
{
	updateAccountBL(m_FilePath, account);
}
void Admin::DeleteAccount(Account* account)
{
	deleteAccountBL(m_FilePath, account, m_Accounts, m_AccountsCount);
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