#pragma once

#include <vector>
#include "../BusinessLogic/AccountBL.h"
#include "../DAOs/AccountDAO.h"

class Admin
{
public:
	Admin(const Admin&) = delete;
	inline static Admin& Get() {return s_Instance;	}
	void Init();
	void OpenAccount(Account* theAccount);
	inline const std::list<Account*> GetOpenAccounts() const { return m_OpenAccounts; }
	inline const std::list<Account*> GetAccounts() const { return m_Accounts; }
	inline const std::size_t GetAccountsCount() const { return m_AccountsCount; }
	void MakeAccount(char name[20]);
	void UpateAccount(Account* account);
	void DeleteAccount(Account* account);
	void ExitAccount(Account* account);
	bool SaveData();
private:
	Admin() : m_AccountsCount(0), m_FilePath("../Data/") {}
	~Admin();
	const char* m_FilePath;
	void _loadData();
	static Admin s_Instance;
	size_t m_AccountsCount;
	std::list<Account*> m_Accounts;
	std::list<Account*> m_OpenAccounts;
};


