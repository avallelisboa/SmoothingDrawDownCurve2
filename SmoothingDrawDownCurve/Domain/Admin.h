#pragma once

#include "../BusinessLogic/AccountBL.h"
#include "Models/ValidationModels/CreateAccountResult.h"
#include "Models/ValidationModels/UpdateAccountResult.h"
#include "Models/ValidationModels/DeleteAccountResult.h"

#include <filesystem>

class Admin
{
public:
	//Delete copy constructor
	Admin(const Admin&) = delete;
	//Getters
	inline static Admin& Get() { return s_Instance; }
	//Public methods
	inline const std::list<Account*> GetAccounts() const { return m_Accounts; }
	inline const std::size_t GetAccountsCount() const { return m_AccountsCount; }
	bool LoadData();
	AddRResult AddR(Account* theAccount, int r);
	CreateAccountResult MakeAccount(char name[20]);
	UpdateAccountResult UpdateAccount(Account* theAccount, std::filesystem::path filePath);
	DeleteAccountResult DeleteAccount(Account* account);
private:
#ifdef _DEBUG
	Admin() : m_AccountsCount(0), m_FilePath("MockUpData/") {}
#else
	Admin() : m_AccountsCount(0), m_FilePath("Data/") {}
#endif
	~Admin();
	//Members
	std::filesystem::path m_FilePath;
	static Admin s_Instance;
	size_t m_AccountsCount;
	std::list<Account*> m_Accounts;
	//Release memory
	void _cleanUp();
	void _cleanUpAccounts();
	void _cleanRs(Account* theAccount);
	void _cleanEquities(Account* theAccount);
	void _cleanAverages(Account* theAccount);
};