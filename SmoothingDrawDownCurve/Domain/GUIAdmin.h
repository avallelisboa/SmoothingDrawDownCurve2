#pragma once
#include <cmath>
#include <matplot/matplot.h>

#include "../BusinessLogic/Plotting.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#include "Admin.h"
#include "Models/Structures/AccountRef.h"

#include <vector>
#include <exception>

class GUIAdmin
{
private:
	GUIAdmin();
	~GUIAdmin();
	//static
	static GUIAdmin s_Instance;
	//members
	bool m_mustShowCreateAccountWindow;
	char m_accountToCreateName[20];
	std::list<Account*> m_accounts;
	std::vector<AccountRef*> m_accountsReferences;
	bool m_wasError = false;
	std::string m_errorMessage;
	//Private functions
	void _makeAccountsReferences();
	void _loadData();
	void _updateAccountsList();
	void _deleteSelectedAccounts();
	//Release memory
	void cleanUp();
public:
	//Delete copy constructor
	GUIAdmin(GUIAdmin&) = delete;
	//Getters
	inline static GUIAdmin& Get() { return s_Instance; }
	inline bool mustShowCreateAccountWindow() { return m_mustShowCreateAccountWindow; }
	inline std::vector<AccountRef*>& getAccountsReferences() { return m_accountsReferences; }
	//public methods definition
	void initApp();
	void createAccount();
	void showCreateAccountWindow();
	void addOperation(AccountRef& theAccount, bool* p_open);
	void graphicData(AccountRef& theAccount);
	void closeAccount(AccountRef& theAccount);
	void showOpenAccountWindow(AccountRef& theAccount, bool* p_open);
	void showAccountsListWindow();
	void showOpenAccountsWindows();

};