#pragma once

#include "../BusinessLogic/AccountBL.h"
#include "../DAOs/AccountDAO.h"
#include "Models/ValidationModels/CreateAccountResult.h"
#include "Models/ValidationModels/UpdateAccountResult.h"
#include "Models/ValidationModels/DeleteAccountResult.h"

class Admin
{
public:
	//Delete copy constructor
	Admin(const Admin&) = delete;
	//Getters
	inline static Admin& Get() { return s_Instance; }
	//Set release or testing data folder in DEBUG mode
#ifdef _DEBUG
	inline void SetTestingMode() { m_FilePath = "MockUpData/"; }
	inline void SetReleaseMode() { m_FilePath = "Data/"; }
#endif
	//Public methods
	bool Init();
	inline const std::list<Account*> GetAccounts() const { return m_Accounts; }
	inline const std::size_t GetAccountsCount() const { return m_AccountsCount; }
	AddRResult AddR(Account* theAccount, int r);
	CreateAccountResult MakeAccount(char name[20]);
	UpdateAccountResult UpdateAccount(Account* theAccount, const char* filePath);
	DeleteAccountResult DeleteAccount(Account* account);
private:
	Admin() : m_AccountsCount(0), m_FilePath("Data/") {}
	~Admin();
	//Members
	const char* m_FilePath;
	bool _loadData();
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