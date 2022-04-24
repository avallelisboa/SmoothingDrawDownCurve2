#pragma once
#include <iostream>
#include <list>
#include "../Account.h"

struct GetAccountsResult {
	bool wasReadFromFile;
	std::string errorMessage;
	std::list<Account*> accounts;
};